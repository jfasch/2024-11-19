plan
====

* start from original intro.cpp
* wrap string into ``class Item``

  * initially have member "prefix" in one of the derived classes (for
    later, lambda capture)
  * PITFALL #1
  * def ctor necessary for std::map, when inserting via operator[]()
  * show how map::insert() is used
  * explain how [] works (maybe show crap)
  * upside: code instantiated as-used!

* current state: Item is just std::string, with added code in doit()

  -> just as lightweight

* actually do something

  * step 1: just one type ("up 1 to 10")
  * expected problems: map type, loop body -> enter polymorphic
  * interface (link! jjj)
  * complete nonsense (but straightforward to run into)

    * map: value is Item (instance)
    * -> blah cannot blah abstract type
    * ok lets not make it abstrace
    * fix dowstream
    * run -> base class method called
    * -> slicing!

  * ok, no slicing, real interfaces

    * allocate objects on stack, and store pointer in map

  * can we make some ``override`` demo out of this? jjj

* memory mgmt -> unique_ptr

  * alloc on heap (stack pointers are ... weird?)
  * unique_ptr: hack, read compiler errors, explain, curse
  * -> "shared_ptr would have been far too simple"

* back to script: brace init

  * compiler says "no"
  * -> use shared_ptr
  * "don't do this lightly!!" (i do it only to move on quickly)

  * -> const todo_list

* auto all over (const&)
* tuple unpacking
* towards lambda: <functional>, callables

  * overload operator()()
  * show usage outside of convoluted shared_ptr usage in map
  * blah virtual overhead blah code size blah
  * <functional>, and *copy instances* into map
  * eliminate interface -> substituted by ``std::function<void()>``

* lambda. well ...
* threads

  * design: union wanted (either std::function<void()>, or running
    std::thread
  * look in https://en.cppreference.com/w/cpp/language/union :-)
  * std::variant

    * naively start with 

      .. code-block:: c++

         using tdl_value = 
             std::variant<
                 std::function<void()>,
                 std::thread
             >;
     
    * notice that std::thread is not copyable
    * brace init requires that though
    * workaround: wrap std::thread in std::shared_ptr
