# Simple Arduino Utilities Alpha2
Very early alpha of a utility library

---

## Super brief temporary documentation

### Miscelleneous functions

`absT`, `minT`, `maxT` - templated equivalents of the arduino macros.
Has shown to provide a small memory saving versus the macro version in certain situations.

`clampT`:
the first argument is your value,
the second argument is the lower bound,
the third argument is the upper bound

`stdlib::swap` - swaps any two variables, e.g.
```cpp
int a = 5;
int b = 6;

stdlib::swap(a, b);

// a is now 6
// b is now 5
```

### Flash string

Use like:
```cpp
const char text[] PROGMEM = "Some Text";

// Option A
arduboy.println(AsFlashString(&text[0]));

// Option B
arduboy.println(AsFlashString(text));
```

### Data structures

* `Array<Type, Capacity>`
* `List<Type, Capacity>`
* `Stack<Type, Capacity>`
* `Queue<Type, Capacity>`
* `Deque<Type, Capacity>`
* `Grid<Type, Width, Height>`

#### Array

**Common:**
* `bool isEmpty() const`
* `bool isFull() const`
* `uint8_t getCount() const`
* `uint8_t getCapacity() const`
* `Type * getData()`
* `const Type * getData() const`
* `Type * operator[](const uint8_t & index)`
* `const Type * operator[](const uint8_t & index) const`
* `void clear()`
* `void fill(const Type & item)`
* `bool contains(const Type & item)`
  * Returns `true` if found, `false` if not found
* `int8_t indexOfFirst(const Type & item)`
  * Returns `-1` if not found
* `int8_t indexOfLast(const Type & item)`
  * Returns `-1`  if not found

#### List

**Specific:**
* `bool add(const Type & item)`
  * Returns `true` on success, `false` on failure
* `bool removeFirst(const Type & item)`
  * Returns `true` on success, `false` on failure
* `bool removeLast(const Type & item)`
  * Returns `true` on success, `false` on failure
* `bool removeAt(const uint8_t & index)`
  * Returns `true` on success, `false` on failure
* `bool insert(const uint8_t & index, const Type & item)`
  * Returns `true` on success, `false` on failure

**Common:**
* `bool isEmpty() const`
* `bool isFull() const`
* `uint8_t getCount() const`
* `uint8_t getCapacity() const`
* `Type * getData()`
* `const Type * getData() const`
* `Type * operator[](const uint8_t & index)`
* `const Type * operator[](const uint8_t & index) const`
* `void clear()`
* `void fill(const Type & item)`
* `bool contains(const Type & item)`
  * Returns `true` if found, `false` if not found
* `int8_t indexOfFirst(const Type & item)`
  * Returns `-1` if not found
* `int8_t indexOfLast(const Type & item)`
  * Returns `-1` if not found
  
#### Stack

**Specific:**
* `Type & peek()`
  * Return result is undefined if stack is empty
* `const Type & peek() const`
  * Return result is undefined if stack is empty
* `bool push(const Type & item)`
  * Returns `true` on success, `false` on failure
* `void drop()`
  * Does nothing if stack is empty
* `bool removeFirst(const uint8_t & index)`
  * Returns `true` on success, `false` on failure
* `bool removeLast(const uint8_t & index)`
  * Returns `true` on success, `false` on failure
* `bool removeAt(const uint8_t & index)`
  * Returns `true` on success, `false` on failure
* `bool insert(const uint8_t & index, const Type & item)`
  * Returns `true` on success, `false` on failure

**Common:**
* `bool isEmpty() const`
* `bool isFull() const`
* `uint8_t getCount() const`
* `uint8_t getCapacity() const`
* `Type * getData()`
* `const Type * getData() const`
* `Type * operator[](const uint8_t & index)`
* `const Type * operator[](const uint8_t & index) const`
* `void clear()`
* `void fill(const Type & item)`
* `bool contains(const Type & item)`
  * Returns `true` if found, `false` if not found
* `int8_t indexOfFirst(const Type & item)`
  * Returns `-1` on failure
* `int8_t indexOfLast(const Type & item)`
  * Returns `-1` if not found
  
#### Queue

**Specific:**
* `Type & peek()`
  * Return result is undefined if queue is empty
* `const Type & peek() const`
  * Return result is undefined if queue is empty
* `bool enqueue(const Type & item)`
  * Returns `true` on success, `false` on failure
* `void dequeue()`
  * Does nothing if queue is empty
* `bool removeFirst(const uint8_t & index)`
  * Returns `true` on success, `false` on failure
* `bool removeLast(const uint8_t & index)`
  * Returns `true` on success, `false` on failure
* `bool removeAt(const uint8_t & index)`
  * Returns `true` on success, `false` on failure
* `bool insert(const uint8_t & index, const Type & item)`
  * Returns `true` on success, `false` on failure

**Common:**
* `bool isEmpty() const`
* `bool isFull() const`
* `uint8_t getCount() const`
* `uint8_t getCapacity() const`
* `Type * getData()`
* `const Type * getData() const`
* `Type * operator[](const uint8_t & index)`
* `const Type * operator[](const uint8_t & index) const`
* `void clear()`
* `void fill(const Type & item)`
* `bool contains(const Type & item)`
  * Returns `true` if found, `false` if not found
* `int8_t indexOfFirst(const Type & item)`
  * Returns `-1` on failure
* `int8_t indexOfLast(const Type & item)`
  * Returns `-1` if not found
  
#### Deque

**Specific:**
* `Type & getFirst()`
  * Return result is undefined if deque is empty
* `const Type & getFirst() const`
  * Return result is undefined if deque is empty
* `Type & getLast()`
  * Return result is undefined if deque is empty
* `const Type & getLast() const`
  * Return result is undefined if deque is empty
* `bool append(const Type & item)`
  * Returns `true` on success, `false` on failure
* `bool prepend(const Type & item)`
  * Returns `true` on success, `false` on failure
* `void unappend()`
  * Does nothing if deque is empty
* `void unprepend()`
  * Does nothing if deque is empty
* `bool removeFirst(const uint8_t & index)`
  * Returns `true` on success, `false` on failure
* `bool removeLast(const uint8_t & index)`
  * Returns `true` on success, `false` on failure
* `bool removeAt(const uint8_t & index)`
  * Returns `true` on success, `false` on failure
* `bool insert(const uint8_t & index, const Type & item)`
  * Returns `true` on success, `false` on failure

**Common:**
* `bool isEmpty() const`
* `bool isFull() const`
* `uint8_t getCount() const`
* `uint8_t getCapacity() const`
* `Type * getData()`
* `const Type * getData() const`
* `Type * operator[](const uint8_t & index)`
* `const Type * operator[](const uint8_t & index) const`
* `void clear()`
* `void fill(const Type & item)`
* `bool contains(const Type & item)`
  * Returns `true` if found, `false` if not found
* `int8_t indexOfFirst(const Type & item)`
  * Returns `-1` on failure
* `int8_t indexOfLast(const Type & item)`
  * Returns `-1` if not found
    
#### Grid

**Specific:**
* `uint8_t getWidth() const`
* `uint8_t getHeight() const`
* `Type & getItem(const uint8_t & x, const uint8_t & y)`
* `const Type & getItem(const uint8_t & x, const uint8_t & y) const`

**Common:**
* `uint8_t getCapacity() const` **or** `uint16_t getCapacity() const`
* `void clear()`
* `void fill(const Type & item)`

---

What about `TypeTraits.h`?
If you have to ask, you ain't gonna need it.
