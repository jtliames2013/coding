359. Logger Rate Limiter 
Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.

Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.

It is possible that several messages arrive roughly at the same time.

Example:

Logger logger = new Logger();

// logging string "foo" at timestamp 1
logger.shouldPrintMessage(1, "foo"); returns true; 

// logging string "bar" at timestamp 2
logger.shouldPrintMessage(2,"bar"); returns true;

// logging string "foo" at timestamp 3
logger.shouldPrintMessage(3,"foo"); returns false;

// logging string "bar" at timestamp 8
logger.shouldPrintMessage(8,"bar"); returns false;

// logging string "foo" at timestamp 10
logger.shouldPrintMessage(10,"foo"); returns false;

// logging string "foo" at timestamp 11
logger.shouldPrintMessage(11,"foo"); returns true;
Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Hash Table Design
Hide Similar Problems (M) Design Hit Counter

  class Logger {
  public:
      /** Initialize your data structure here. */
      Logger() {

      }

      /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
          If this method returns false, the message will not be printed.
          The timestamp is in seconds granularity. */
      bool shouldPrintMessage(int timestamp, string message) {
    	  auto iter=time.find(message);
    	  if (iter==time.end()) {
    		  time[message]=timestamp;
    		  return true;
    	  } else {
    		  if (timestamp-iter->second<10) return false;
    		  else {
    			  time[message]=timestamp;
    			  return true;
    		  }
    	  }
      }
  private:
      unordered_map<string, int> time;
  };

  /**
   * Your Logger object will be instantiated and called as such:
   * Logger obj = new Logger();
   * bool param_1 = obj.shouldPrintMessage(timestamp,message);
   */

