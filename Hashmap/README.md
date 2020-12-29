# Hashmap

Unordered hashmap implementation using linked lists.

Hashing of key values using `xxHash`

```cpp
Hashmap<int, int> map;
map[10] = 20;
map[11] = 21;

map.count(10);
map.count(30);

int a = map[10];
```


# More info
- [HashTable](https://en.wikipedia.org/wiki/Hash_table)
- [xxHash](https://github.com/Cyan4973/xxHash)