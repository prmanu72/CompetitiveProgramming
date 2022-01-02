### 1. IsUnique 
`Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures? `

Q: What character set, ASCII or UNICODE?

#### Sol 1: Create a boolean array of size 128(or 256) and parse through array
```
TC: O(1) or O(c) | c : size of character set
SC: O(1) constant space complexity
```

#### Sol 2: Use bit vector 
```
TC : O(1)
SC : O(1)
```
#### Sol 3: Compare every character with other character
```
TC : O(n^2)
SC : O(1)
```
#### Sol 4: Sort and iterate through array
```
TC : O(nlogn)
SC : O(1)
```

#### Sol 1
```
 boolean isUniqueChars(String str) {
 if (str.length() > 128) return false;

 boolean[] char_set = new boolean[128];
 for (int i= 0; i < str.length(); i++) {
  int val= str.charAt(i);
  if (char_set[val]) {//Already found this char in string
    return false;
  }
  char_set[val] = true;
 }
 return true;
 }
```

#### Sol 2
```
boolean isUniqueChars(String str) {
 int checker= 0;
 for (int i= 0; i < str.length(); i++) {
 int val= str.charAt(i) - 'a';
 if ((checker & (1 << val)) > 0) {
 return false;
 }
 checker I= (1 << val);
 }
 return true;
 }
```
