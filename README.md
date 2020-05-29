# Vectorius

# 1.

Įsitikinsime, kad Vector konteineris veikia (funkcionalumo prasme) lygiai taip pat, kaip ir std::vector. 

Tam atlikti panaudojome: konstruktorių, destruktorių, size(), capacity(), '=' operatorių, '[]' priėjimą prie elementų, push_back() funkcijas.

![](Vector/ooop.JPG)

Rezultatai rodo, kad nuosavo vektoriaus visos funkcijos veikia taip pat ir std::vector.

# 2.

Atlikta efektyvumo/spartos analizė:

|               |     10000     |     100000    |     1000000   |    10000000   |    100000000  |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
|    Vector     |       0       |    0.002      |    0.012      |     0.139     |     1.332     |
|  std::vector  |      0.001    |     0.001     |     0.013     |   0.182       |      1.462    |

Tiek Vector tiek std::vector veikia labai panasiai, bet šiaip Vector yra minimaliai greitesnis.

# 3.

