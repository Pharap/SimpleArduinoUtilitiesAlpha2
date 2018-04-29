# Simple Arduino Utilities Alpha2
Very early alpha of a utility library

---

## Super brief temporary documentation

### Data structures

* `Array<Type, Capacity>`
  * `Type * getData(void)`
  * `const Type * getData(void) const`  
* `List<Type, Capacity>`
* `Stack<Type, Capacity>`
* `Queue<Type, Capacity>`
* `Deque<Type, Capacity>`
* `Grid<Type, Width, Height>`

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

---

What about `TypeTraits.h`?
If you have to ask, you ain't gonna need it.
