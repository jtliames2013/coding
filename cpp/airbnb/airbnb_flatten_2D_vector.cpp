251. Flatten 2D Vector 
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

Hint:

How many variables do you need to keep track?
Two variables is all you need. Try with x and y.
Beware of empty rows. It could be the first few rows.
To write correct code, think about the invariant to maintain. What is it?
The invariant is x and y must always point to a valid point in the 2d vector. Should you maintain your invariant ahead of time or right when you need it?
Not sure? Think about how you would implement hasNext(). Which is more complex?
Common logic in two different places should be refactored into a common method.
Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.

Hide Company Tags Google Airbnb Twitter Zenefits
Hide Tags Design
Hide Similar Problems (M) Binary Search Tree Iterator (M) Zigzag Iterator (M) Peeking Iterator (M) Flatten Nested List Iterator

1. Use iterator

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        v2d=vec2d;
        rowIter=v2d.begin();
        if (rowIter!=v2d.end()) colIter=rowIter->begin();
        tryAdvance();
    }

    void tryAdvance() {
        while (rowIter!=v2d.end()) {
            if (colIter!=rowIter->end()) break;
            rowIter++;
            colIter=rowIter->begin();
        }    
    }
    
    int next() {
        if (hasNext()) {
            int res=*colIter;
            colIter++;
            tryAdvance();
            return res;
        } else {
            return 0;
        }
    }

    bool hasNext() {
        if (rowIter!=v2d.end()) return true;
        else return false;
    }
private:
    vector<vector<int>> v2d;
    vector<vector<int>>::iterator rowIter;
    vector<int>::iterator colIter;
};

2. Use index

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        v2d=vec2d;
        size=v2d.size();
        row=0;
        idx=0;
        tryAdvance();
    }

    void tryAdvance() {
        while (row<size) {
            if (idx<v2d[row].size()) break;
            row++;
            idx=0;
        }    
    }
    
    int next() {
        if (hasNext()) {
            int res=v2d[row][idx];
            idx++;
            tryAdvance();
            return res;
        } else {
            return 0;
        }
    }

    bool hasNext() {
        if (row<size) return true;
        else return false;
    }
private:
    vector<vector<int>> v2d;
    int size;
    int row;
    int idx;
};

3. Implement remove() that remove the previous next
class Vector2D {
  public:
	  void tryAdvance() {
		  while (row<vec2d.size()) {
			  if (col<vec2d[row].size()) break;
			  row++;
			  col=0;
		  }
	  }
      Vector2D(vector<vector<int>>& vec2d) {
    	  this->vec2d=vec2d;
    	  row=0;
    	  col=0;
    	  removeRow=-1;
    	  removeCol=-1;
    	  tryAdvance();
      }

      int next() {
    	  if (hasNext()) {
    		  int res=vec2d[row][col];
    		  removeRow=row;
    		  removeCol=col;
    		  col++;
    		  tryAdvance();
    		  return res;
    	  } else {
    		  return -1;
    	  }
      }

      bool hasNext() {
    	  if (row>=vec2d.size()) return false;
    	  else return true;
      }

      void remove() {
    	  if (removeRow==-1) return;
    	  if (removeRow==row) {
    		  vec2d[removeRow].erase(vec2d[removeRow].begin()+removeCol);
    		  col--;
    	  } else {
    		  vec2d[removeRow].erase(vec2d[removeRow].begin()+removeCol);
    		  if (vec2d[removeRow].size()==0) {
    			  vec2d.erase(vec2d.begin()+removeRow);
    			  row--;
    		  }
    	  }
    	  removeRow=removeCol=-1;
      }

      void printV2D() {
     	 for (int i=0; i<vec2d.size(); i++) {
     		 for (int j=0; j<vec2d[i].size(); j++) {
     			 cout << vec2d[i][j] << " ";
     		 }
     		 cout << endl;
     	 }
      }
  private:
      int row;
      int col;
      int removeRow;
      int removeCol;
      vector<vector<int> > vec2d;
  };

 void printV(vector<vector<int> > v2d) {
	 for (int i=0; i<v2d.size(); i++) {
		 for (int j=0; j<v2d[i].size(); j++) {
			 cout << v2d[i][j] << " ";
		 }
		 cout << endl;
	 }

 }

  int main() {
	  vector<vector<int> > v2d={{1},{2,3},{},{4,5,6}};
	  Vector2D s(v2d);
	  while (s.hasNext()) {
		  cout << s.next() << endl;
		  s.remove();
		  s.printV2D();
	  }
	  return 0;
  }

