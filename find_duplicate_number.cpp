这道题（据说）花费了计算机科学界的传奇人物Don Knuth 24小时才解出来。并且我只见过一个人（Keith Amling）用更短时间解出此题。

问题的第一部分 - 证明至少存在一个重复元素 - 是鸽笼原理的直接应用。如果元素的范围是[1, n]，那么只存在n种不同的值。如果有n+1个元素，其中一个必然重复。

问题的第二部分 - 在给定约束条件下寻找重复元素 - 可就难多了。 要解决这个问题，我们需要敏锐的洞察力，使问题通过一列的转化，变为一个完全不同的问题。

解决本题需要的主要技巧就是要注意到：由于数组的n + 1个元素范围从1到n，我们可以将数组考虑成一个从集合{1, 2, ..., n}到其本身的函数f。这个函数的定义为f(i) = A[i]。基于这个设定，重复元素对应于一对下标i != j满足 f(i) = f(j)。我们的任务就变成了寻找一对(i, j)。一旦我们找到这个值对，只需通过f(i) = A[i]即可获得重复元素。

但是我们怎样寻找这个重复值呢？这变成了计算机科学界一个广为人知的“环检测”问题。问题的一般形式如下：给定一个函数f，序列x_i的定义为

    x_0     = k       (for some k)
    x_1     = f(x_0)
    x_2     = f(f(x_0))
    ...
    x_{n+1} = f(x_n)

假设函数f从定义域映射到它本身，此时会有3种情况。首先，如果定义域是无穷的，则序列是无限长并且没有循环的。例如，函数 f(n) = n + 1，在整数范围内满足这个性质 - 没有数字是重复的。 第二， 序列可能是一个闭合循环，这意味着存在一个i使得x_0 = x_i。在这个例子中，序列在一组值内无限循环。第三，序列有可能是的“ρ型的”，此时序列看起来像下面这样：

      x_0 -> x_1 -> ... x_k -> x_{k+1} ... -> x_{k+j}
                         ^                       |
                         |                       |
                         +-----------------------+

也就是说，序列从一列链条型的元素开始进入一个环，然后无限循环。我们将环的起点称为环的“入口”。

对于从数组中寻找重复元素这个问题，考虑序列从位置n开始重复调用函数f。亦即从数组的最后一个元素开始，然后移动到其元素值对应的下标处，并且重复此过程。可以得到：此序列是ρ型的。要明白这一点，需要注意到其中一定有环，因为数组是有限的并且当访问n个元素时，一定会对某个元素访问两次。无论从数组的哪一个位置开始，这都是成立的。

另外，注意由于数组元素范围1到n，因此不存在值为0的元素。进而，从数组的第一个元素开始调用一次函数f之后，再也不会回到这里。这意味着第一个元素不会是环的一部分，但如果我们继续重复调用函数f，最终总会访问某个节点两次。从0节点开始的链条与环形相接，使得其形状一定是ρ型。

此外，考虑一下环的入口。由于节点位于环的入口，一定存在两个输入，其对应的函数f的输出值都等于入口元素下标。要使其成立，一定存在两个下标i != j，满足f(i) = f(j)，亦即A[i] = A[j]。因而环的入口一定是重复值。

这是由Robert Floyd提出的一个著名算法，给定一个ρ型序列，在线性时间，只使用常数空间寻找环的起点。这个算法经常被称为“龟兔”算法，至于原因下面就明白了。
算法背后的思想是定义两个变量。首先，令c为进入环的链的长度，然后令l为环的长度。接下来，令l'为大于c的l的倍数的最小值。可以得出结论：对于上文定义的任意ρ型序列的l'，都有
 
     x_{l'} = x_{2l'}
 
证明实际上非常直观并且具有自明性 - 这是计算机科学中我最喜欢的证明之一。思路就是由于l'至少为c，它一定包含在环内。同时，由于l'是环长度的倍数，我们可以将其写作ml，其中m为常数。如果我们从位置x_{l'}开始（其在环内），然后再走l'步到达x_{2l'}，则我们恰好绕环m次，正好回到起点。

Floyd算法的一个关键点就是即使我们不明确知道c的值，依然可以在O(l')时间内找到值l'。思路如下。我们追踪两个值"slow"和"fast"，均从x_0开始。然后迭代计算
 
     slow = f(slow)
     fast = f(f(fast))
 
我们重复此步骤直到slow与fast彼此相等。此时，我们可知存在j满足slow = x_j，并且fast = x_{2j}。 由于x_j = x_{2j}，可知j一定至少为c，因为此时已经在环中。另外，可知j一定是l的倍数，因为x_j = x_{2j}意味着在环内再走j步会得到同样的结果。最后，j一定是大于c的l的最小倍数，因为如果存在一个更小的大于c的l的倍数，我们一定会在到达j之前到达那里。所以，我们一定有j = l'，意味着我们可以在不知道环的长度或者形状的情况下找到l'。

要完成整个过程，我们需要明白如何使用l'来找到环的入口（记为x_c）。要做到这一步，我们再用最后一个变量，记为"finder"，从x_0出发。然后迭代重复执行过程：

 
    finder = f(finder)
    slow   = f(slow)
 
直到finder = slow为止。我们可知：(1) 两者一定会相遇 (2) 它们会在环的入口相遇。 要理解这两点，我们注意由于slow位于x_{l'}，如果我们向前走c步，那么slow会到达位置x_{l' + c}。由于l'是环长度的倍数，相当于向前走了c步，然后绕环几圈回到原位。换言之，x_{l' + c} = x_c。另外，考虑finder变量在行进c步之后的位置。 它由x_0出发，因此c步之后会到达x_c。这证明了(1)和(2)，由此我们已经证明两者最终会相遇，并且相遇点就是环的入口。

算法的美妙之处在于它只用O(1)的额外存储空间来记录两个不同的指针 - slow指针和fast指针（第一部分），以及finder指针（第二部分）。但是在此之上，运行时间是O(n)的。要明白这一点，注意slow指针追上fast指针的时间是O(l')。由于l'是大于c的l的最小倍数，有两种情况需要考虑。首先，如果l > c，那么就是l。 否则，如果l < c，那么我们可知一定存在l的倍数介于c与2c之间。要证明这一点，注意在范围c到2c内，有c个不同的值，由于l < c，其中一定有值对l取模运算等于0。最后，寻找环起点的时间为O(c)。这给出了总的运行时间至多为O(c + max{l, 2c})。所有这些值至多为n，因此算法的运行时间复杂度为O(n)。

class Solution(object):
    def findDuplicate(self, nums):
        # The "tortoise and hare" step.  We start at the end of the array and try
        # to find an intersection point in the cycle.
        slow = 0
        fast = 0
    
        # Keep advancing 'slow' by one step and 'fast' by two steps until they
        # meet inside the loop.
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
    
            if slow == fast:
                break
    
        # Start up another pointer from the end of the array and march it forward
        # until it hits the pointer inside the array.
        finder = 0
        while True:
            slow   = nums[slow]
            finder = nums[finder]
    
            # If the two hit, the intersection index is the duplicate element.
            if slow == finder:
                return slow

