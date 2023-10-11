import timeit
import math
from collections import defaultdict

def disasterCode():
    existingPrimes = set([2])
    for i in range (3, round(math.sqrt(2500))+1, 2):
        prime = True
        for j in existingPrimes:
            if i%j==0:
                prime = False
                break
        if prime:
            existingPrimes.add(i)
            
    
    prime_factors = defaultdict(set)
    for i in range (2,2500):
        currentPrime = i
        flag = True
        for j in existingPrimes:
            if currentPrime%j == 0:
                flag = False
                prime_factors[i].add(j)
                currentPrime /= j
                prime_factors[i] = prime_factors[i].union(prime_factors[currentPrime])
                break
        if(flag == True):
            prime_factors[i].add(currentPrime)
                

# Benchmark the code
if __name__ == "__main__":
    benchmark_code = "disasterCode()"
    setup_code = "from __main__ import disasterCode"

    # Measure the execution time of disasterCode function
    times = []
    for i in range(0,5):
        times.append(timeit.timeit(benchmark_code, setup=setup_code, number=1))

    res = sum(times)/5

    print(f"Average execution time after 5 runs: {res:.6f} seconds")
