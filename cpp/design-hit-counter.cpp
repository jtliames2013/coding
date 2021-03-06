362. Design Hit Counter
Medium

467

47

Favorite

Share
Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:

HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301); 
Follow up:
What if the number of hits per second could be very large? Does your design scale?

Amazon
|
6

Google
|
3

Oracle
|
3

Microsoft
|
3

Quip (Salesforce)
|
2

Apple
|
2

Booking.com
|
2

Visa
|
2

1. deque
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        hits=0;
    }
    
    void removeHits(int timestamp) {
        while (!dq.empty() && dq.front().first<=timestamp-300) {
            hits-=dq.front().second;
            dq.pop_front();
        }
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        removeHits(timestamp);
        if (!dq.empty() && dq.back().first==timestamp) dq.back().second++;
        else dq.push_back({timestamp,1});
        hits++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        removeHits(timestamp);
        return hits;
    }
private:
    deque<pair<int,int>> dq;
    int hits;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

2. circular array
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        size=300;
        hits=0;
        count.resize(size);
        lastTime=lastPos=0;
    }
    
    void removeHits(int timestamp) {
        // clear between current position of timestamp and last position
        int gap=min(size, timestamp-lastTime);
        for (int i=0; i<gap; i++) {
            lastPos=(lastPos+1)%size;
            hits-=count[lastPos];
            count[lastPos]=0;
        }
        lastTime=timestamp;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        removeHits(timestamp);
        count[lastPos]++;
        hits++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        removeHits(timestamp);
        return hits;
    }
private:
    vector<int> count;
    int hits;
    int size;
    int lastTime;
    int lastPos;
};

