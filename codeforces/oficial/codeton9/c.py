def count_valid_c(x, m):
    def satisfies(c):
        # Check if (c * x) ^ x < m
        return (c * x) ^ x < m
    
    # Binary search to find the largest c that satisfies the condition
    left, right = 1, 10**18  # Upper bound for c is large
    while left < right:
        mid = (left + right + 1) // 2
        if satisfies(mid):
            left = mid  # mid satisfies, so try larger values
        else:
            right = mid - 1  # mid doesn't satisfy, so try smaller values
    
    return left  # Largest c satisfying the condition

# Example usage
x = 7
m = 10
result = count_valid_c(x, m)
print(result)