#include "Queue.h"
#include <iostream>
using namespace std;
class Test
{
public:
  void runTests();
  string testOutput();
  bool testIsEmptyInital();
  bool testIsEmptyAdd();
  bool testEnQueueOnce();
  bool testEnQueueTwice();
  bool testDeQueueErrorEmpty();
  bool testDeQueueErrorPushPop();
  bool testDeQueuePushPop();
  bool testDeQueueEmpty();
  bool testPeekFrontEmpty();
  bool testAsStack();
  bool testPeekAtBack();
};
