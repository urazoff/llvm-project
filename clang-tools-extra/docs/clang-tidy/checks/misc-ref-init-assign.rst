.. title:: clang-tidy - misc-ref-init-assign

misc-ref-init-assign
====================

Finds assignments of reference type variables after initialization.

Example:

.. code-block:: c++

  int b = 0;
  int &a = b;
  a = 2;  // Warning.

