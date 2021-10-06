# char_arr_to_hex_arr


add below line to your CMakeLists.txt to change size of array;

``` 
example: target_compile_definitions(main PRIVATE SIZE=20) 
```


**Parameters**

* **data:** the data required to be converted to hex string;
* **len:** size of data;
* **out:** must be ```out[SIZE][5]``` to fill converted data.

