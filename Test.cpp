#include "Test.h"

void Test::runTests()
{
  testOutput();
  testIsEmptyInital();
  testIsEmptyAdd();
  testEnQueueOnce();
  testEnQueueTwice();
  testDeQueuePushPop();
  testPeekAtBack();
  testDeQueueErrorEmpty();
  testDeQueueErrorPushPop();
  testDeQueueEmpty();
  testPeekFrontEmpty();
  testAsStack();
}
string Test::testOutput()
{
  Queue testQueue;
  cout << "test1\n";
  return "test\n";
}

bool Test::testIsEmptyInital()
{
  cout << "Test 1: IsEmpty returning true for empty Queue: ";
  Queue testQueue;
  if (testQueue.isEmpty())
  {
    cout << "ACCEPT\n";
    return true;
  }
  else
  {
    cout << "FAIL\n";
    return false;
  }
}


bool Test::testIsEmptyAdd()
{
  cout << "Test 2: Check if is empty returns false for non empty Queue: ";
  Queue testQueue;
  testQueue.enqueue(1);
  if (!testQueue.isEmpty())
  {
    cout << "ACCEPT\n";
    return true;
  }
  else
  {
    cout << "FAIL\n";
    return false;
  }testEnQueueOnce();
}

bool Test::testEnQueueOnce()
{
  cout << "Test 3: Pushing value to empty Queue produces right value: ";
  int testval = 1000;
  Queue testQueue;
  testQueue.enqueue(testval);
  if (testval == testQueue.peekFront())
  {
    cout << "ACCEPT\n";
    return true;
  }
  cout << "FAIL\n";
  return false;
}

bool Test::testEnQueueTwice()
{
  cout << "Test 4: Push value to empty Queue twice is first value produced in front of Queue: ";
  int testval1 = 100;
  int testval2 = 1000;
  Queue testQueue;
  testQueue.enqueue(testval1);
  testQueue.enqueue(testval2);
  if (testval1 == testQueue.peekFront())
  {
    cout << "ACCEPT\n";
    return true;
  }
  cout << "FAIL\n";
  return false;
}

bool Test::testDeQueuePushPop()
{
  cout << "Test 5: Push various values. See if front value popped is first pushed for all pushes.: ";

  Queue testQueue;
  bool errorFlag = true;
  int firstPush(1);
  int secondPush(2);
  int thirdPush(3);
  testQueue.enqueue(1);
  if (testQueue.peekFront() != firstPush)
  {
    errorFlag = false;
  }

  testQueue.enqueue(2);
  if (testQueue.peekFront() != firstPush)
  {
    errorFlag = false;
  }

  testQueue.enqueue(3);
  if (testQueue.peekFront() != firstPush)
  {
    errorFlag = false;
  }
  testQueue.dequeue();
  testQueue.dequeue();

  if (errorFlag == true)
  {
    cout << "ACCEPT\n";
    return true;
  }

  else
  {
    cout << "FAIL\n";
    return false;
  }

}

bool Test::testPeekAtBack()
{
  cout << "Test 6: Push various values. Return fail if deQueued values ack as if popped off back: ";

  Queue testQueue;
  bool errorFlag = true;
  int firstPush(1);
  int secondPush(2);
  int thirdPush(3);
  testQueue.enqueue(1);
  testQueue.enqueue(2);
  testQueue.enqueue(3);
  testQueue.dequeue();
  if (testQueue.peekFront() != secondPush)
  {
    errorFlag = false;
  }
  testQueue.dequeue();
  if (testQueue.peekFront() != firstPush)
  {
    errorFlag = false;
  }
  if (errorFlag == true)
  {
    cout << "FAIL\n";
    return false;
  }

  else
  {
    cout << "ACCEPT\n";
    return true;
  }

}

bool Test::testDeQueueErrorEmpty()
{
  cout << "Test 7: Pop Empty Queue. Error?: ";
  try
  {
    Queue testQueue;
    testQueue.dequeue();

  }
  catch(std::runtime_error)
  {
    cout << "ACCEPT\n";
    return true;
  }
  cout << "FAIL\n";
  return false;
}

bool Test::testDeQueueErrorPushPop()
{
  cout << "Test 8: Pop Queue of size 1 twice. Error?: ";
  try
  {
    Queue testQueue;
    testQueue.enqueue(1);
    testQueue.dequeue();
    testQueue.dequeue();

  }
  catch(std::runtime_error)
  {
    cout << "ACCEPT\n";
    return true;
  }
  cout << "FAIL\n";
  return false;
}

bool Test::testDeQueueEmpty()
{
  cout << "Test 9: Push value to empty Queue, pop value. Is empty?: ";
  Queue testQueue;
  testQueue.enqueue(1);
  testQueue.dequeue();
  if (testQueue.isEmpty())
  {
    cout << "ACCEPT\n";
    return true;
  }

  else
  {
    cout << "FALSE\n";
    return false;
  }

}

bool Test::testPeekFrontEmpty()
{
  cout << "Test 10: Peek front of empty Queue. Error?: ";
  try
  {
    Queue testQueue;
    testQueue.peekFront();
  }
  catch(std::runtime_error)
  {
    cout << "ACCEPT\n";
    return true;
  }
  cout << "FAIL\n";
  return false;
}

bool Test::testAsStack()
{
  cout << "Test 11: Returns false if it appears to act as a stack though peeking pushing and popping various states: ";
  Queue testQueue;
  bool stack = true;
  int firstValue = 1;
  int secondValue = 5;
  int thirdValue = 10;

  testQueue.enqueue(firstValue);
  testQueue.enqueue(secondValue);
  if(testQueue.peekFront() != secondValue)
  {
    stack = false;
  }
  testQueue.enqueue(thirdValue);
  if(testQueue.peekFront() != thirdValue)
  {
    stack = false;
  }
  testQueue.dequeue();
  if(testQueue.peekFront() != secondValue)
  {
    stack = false;
  }
  testQueue.dequeue();
  if(testQueue.peekFront() != firstValue)
  {
    stack = false;
  }

  if(stack)
  {
    cout << "FAIL\n";
    return false;
  }
  else
  {
    cout << "ACCEPT\n";
    return true;
  }


}
