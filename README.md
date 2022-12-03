Wormholes
---

A given intergalactic empire needs to create a network between its planets
using wormholes, which connect their planets.

To achieve this goal it is necessary to use purple matter to maintain the
network working inside the wormholes.

Since the empire wants to spend as little purple matter as possible,
they hired a brilliant computer arts student to solve
this problem efficiently.

The empire will cede the planets and the cost in purple matter of each connection of the
wormhole, and requires the minimum cost to maintain the network between these
planets.

### Important Criteria

Regardless of the test results, non-compliance with the criteria below
will result in a zero score for this activity. Any questions please contact us.

* You must solve this problem using graphs, and using the algorithm of
      Kruskal **(implementing the disjoint sets as a forest, using the path compression heuristic and using union-by-rank)**.
    

### Comments

* You must include, at the beginning of your program, a brief header containing at
      least your name and RA.
* Correctly indent your code and include comments throughout your
      program.
*Accepted languages: C

### Input

The first line of the input consists of two integers `n m`, where
`1 <= n <= 1000` and `0 <= m <= n(n - 1)/2`, representing the number of planets
and the number of wormholes, respectively.

Each planet is represented by a numeric code between `0` and `n - 1`.

Each of the next `m` lines consists of a trio of `u v w` integers,
separated by spaces, where `0 <= u, v <= n - 1`, which represents the existence
of a wormhole between planets coded `u` and `v`, and
`-100 <= w <= 100`, which represents the amount of purple matter needed
to make the network work inside the wormhole.

### Output

Your program's response must consist of a single integer `z`, representing
the minimum amount of purple matter needed to maintain the entire network
between the working planets.

### Examples

**Test 01**

Input:

      3 3
      0 1 -5
      0 2 20
      1 2 10
    

Output:

      5
    

**Test 02**

Input:

      6 7
      0 1 -10
      0 2 -20
      1 3 -5
      1 4 20
      2 3 -1
      3 5 15
      4 5 10
    

Output:

      -eleven
    

**Test 03**

Input:

      5 10
      0 1 25
      0 2 10
      0 3 4
      0 4 65
      1 2 15
      1 3 54
      1 4 87
      2 3 65
      2499
      3 4 70
    

Output:

      94
