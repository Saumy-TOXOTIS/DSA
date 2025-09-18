from __future__ import annotations
import json
from pathlib import Path
import textwrap

ROOT = Path(__file__).resolve().parents[1]
BIT_DIR = ROOT / "Bit Manipulation"
OUTPUT = BIT_DIR / "Bit_Manipulation_Problems.ipynb"

cells: list[dict] = []


def to_source_lines(text: str) -> list[str]:
    return [line + "\n" for line in text.splitlines()]


def add_markdown(text: str) -> None:
    text = textwrap.dedent(text).strip("\n")
    cells.append(
        {
            "cell_type": "markdown",
            "metadata": {},
            "source": to_source_lines(text),
        }
    )


def add_code_from(path: Path) -> None:
    source = path.read_text()
    cells.append(
        {
            "cell_type": "code",
            "execution_count": None,
            "metadata": {"language": "cpp"},
            "outputs": [],
            "source": to_source_lines(source),
        }
    )


def add_problem(problem: dict) -> None:
    approach_lines = "\n".join(f"* {line}" for line in problem["approach"])
    text = f"""### {problem['title']}\n\n"""
    text += f"**Problem statement:** {problem['statement']}\n\n"
    text += "**Example:**\n"
    text += "```\n" + problem["example"].strip("\n") + "\n```\n"
    text += f"**Explanation:** {problem['explanation']}\n\n"
    text += "**Approach highlights:**\n"
    text += approach_lines + "\n\n"
    text += f"**Complexity:** Time {problem['time_complexity']}, Space {problem['space_complexity']}."
    add_markdown(text)
    add_code_from(BIT_DIR / problem["file"])


add_markdown(
    """
    # Bit Manipulation Interview Workbook
    """
)

add_markdown(
    """
    Bit-level reasoning frequently unlocks elegant solutions to optimisation puzzles and number-theory questions.
    This notebook curates every bit-manipulation problem in the repository so you can revise the statement,
    walk through an example, understand the core insight, and study the associated C++ implementation in one place.
    """
)

categories: list[dict] = [
    {
        "title": "Bit Manipulation Fundamentals",
        "intro": "Master essential identities for toggling, counting, and checking bits—building blocks for every other trick that follows.",
        "problems": [
            {
                "title": "Counting Set Bits Efficiently",
                "file": "Count_Number_of_Set_bits.cpp",
                "statement": "Given a non-negative integer n, return the number of set bits (1s) in its binary representation.",
                "example": "n = 29\nOutput: 4",
                "explanation": "Repeatedly clearing the lowest set bit with `n & (n - 1)` counts how many ones appear without scanning every position individually.",
                "approach": [
                    "Initialise a counter to zero.",
                    "While n is positive, replace it with `n & (n - 1)` to drop the rightmost one bit.",
                    "Increment the counter on each iteration and return it once all bits are cleared.",
                ],
                "time_complexity": "O(popcount(n))",
                "space_complexity": "O(1)",
            },
            {
                "title": "Counting Bits from 0 to n",
                "file": "Counting_Bits.cpp",
                "statement": "For a given n, produce an array ans where ans[i] is the number of 1 bits in i for all 0 \u2264 i \u2264 n.",
                "example": "n = 5\nOutput: [0, 1, 1, 2, 1, 2]",
                "explanation": "Iterating from 0 through n and applying Brian Kernighan's trick to each value fills the table of set-bit counts.",
                "approach": [
                    "Allocate an array of length n + 1.",
                    "For each integer i, copy it into a temporary variable and repeatedly clear the lowest set bit while counting removals.",
                    "Store the count in ans[i] before moving on to the next number.",
                ],
                "time_complexity": "O(n \u22c5 log n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Check if a Number is a Power of Two",
                "file": "Power_of_Two.cpp",
                "statement": "Return true if a signed integer n is a positive power of two and false otherwise.",
                "example": "n = 16\nOutput: true",
                "explanation": "The implementation guards against non-positive input, computes the base-two logarithm, and checks whether shifting 1 by that exponent recreates n exactly.",
                "approach": [
                    "Reject zero and negative values immediately.",
                    "Compute floor(log2(n)) using the standard library.",
                    "Shift 1 left by the computed exponent and compare it with n to confirm it was an exact power of two.",
                ],
                "time_complexity": "O(1)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Set the Rightmost Unset Bit",
                "file": "Set_Rightmost_Unset_Bit.cpp",
                "statement": "Given an integer n, flip its lowest zero bit (the rightmost unset bit) to one and return the result.",
                "example": "n = 10 (1010)\nOutput: 11 (1011)",
                "explanation": "Using `(n | (n + 1))` sets the lowest zero bit without disturbing higher bits because adding one carries precisely into that position.",
                "approach": [
                    "Observe that adding one to n propagates a carry up to the first zero bit.",
                    "Bitwise OR the original value with n + 1 so that the carry permanently sets that bit.",
                    "Return the updated integer.",
                ],
                "time_complexity": "O(1)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Unset the Rightmost Set Bit",
                "file": "Unset_Rightmost_Set_Bit.cpp",
                "statement": "Remove the lowest set bit of an integer n and return the resulting value.",
                "example": "n = 12 (1100)\nOutput: 8 (1000)",
                "explanation": "The classic identity `n & (n - 1)` clears the least-significant one because subtracting one flips the trailing zeros and that one bit, and the AND operation drops it.",
                "approach": [
                    "Subtract one from n to flip the lowest set bit and all lower positions.",
                    "Bitwise AND the original and decremented values so only the higher bits remain.",
                    "Return the masked result.",
                ],
                "time_complexity": "O(1)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Minimum Bit Flips Between Integers",
                "file": "Minimum_Bit_Flips_to_Convert_Number.cpp",
                "statement": "Compute the minimum number of bit positions that must change to transform start into goal.",
                "example": "start = 10 (1010), goal = 7 (0111)\nOutput: 3",
                "explanation": "XOR highlights exactly the positions that differ, and counting the set bits in that XOR reveals how many flips are required.",
                "approach": [
                    "Take the XOR of start and goal to obtain the difference mask.",
                    "Repeatedly clear the lowest set bit of the mask, counting how many removals occur.",
                    "Return the accumulated count as the minimum flips.",
                ],
                "time_complexity": "O(popcount(start \u2295 goal))",
                "space_complexity": "O(1)",
            },
        ],
    },
    {
        "title": "XOR Patterns and Unique Elements",
        "intro": "XOR's cancellation property makes it perfect for isolating unique values and computing prefix parities.",
        "problems": [
            {
                "title": "Single Number via XOR Folding",
                "file": "Single_Number.cpp",
                "statement": "In an array where every element appears twice except for one number, return the non-duplicated value.",
                "example": "nums = [4, 1, 2, 1, 2]\nOutput: 4",
                "explanation": "Pairwise duplicates cancel under XOR, so folding the entire array with XOR leaves only the single element.",
                "approach": [
                    "Initialise the answer with the first element.",
                    "Iterate through the remaining values, XORing each into the running result.",
                    "Return the final accumulator.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Find Two Numbers Appearing Single Times",
                "file": "Find_Two_Numbers_Appearing_Single_Times.cpp",
                "statement": "Given an array in which exactly two values appear an odd number of times and every other value appears an even number of times, identify the two unique values.",
                "example": "arr = [4, 2, 4, 5, 2, 3, 3, 1]\nOutput: 5 and 1",
                "explanation": "XORing all values yields x \u2295 y where x and y are the odd occurrences. Isolating the rightmost set bit of that XOR splits the array into two groups so each unique number can be recovered individually.",
                "approach": [
                    "XOR all numbers to obtain the combined value x \u2295 y.",
                    "Extract the rightmost set bit using `xor_sum & -xor_sum` to distinguish between the two targets.",
                    "Partition the original array based on that bit and XOR within each partition to recover the isolated numbers.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "XOR of a Range",
                "file": "Find_XOR_of_Range_L_to_R.cpp",
                "statement": "Return the XOR of every integer in the inclusive range [l, r].",
                "example": "l = 3, r = 9\nOutput: 2",
                "explanation": "The XOR of 0 through n follows a repeating pattern with period four. Leveraging that prefix pattern allows the range XOR to be computed as prefix(r) \u2295 prefix(l-1).",
                "approach": [
                    "Implement a helper that returns the XOR of all numbers from 0 to n using the modulo-4 pattern.",
                    "Evaluate the helper at r and at l - 1.",
                    "XOR the two prefix results to obtain the answer for [l, r].",
                ],
                "time_complexity": "O(1)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Enumerate All Subsets with Bit Masks",
                "file": "Power_Set_or_Subsets.cpp",
                "statement": "Generate every subset of an integer array.",
                "example": "nums = [1, 2, 3]\nOutput: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]",
                "explanation": "Treat each subset as a bit mask between 0 and 2^n - 1; checking whether bit j is set decides if nums[j] belongs to the subset.",
                "approach": [
                    "Compute the total number of subsets as 1 << n where n is the array length.",
                    "Iterate over all bit masks from 0 up to but excluding 2^n.",
                    "For each mask, inspect every bit and push the corresponding element when the bit is set.",
                ],
                "time_complexity": "O(n \u22c5 2^n)",
                "space_complexity": "O(n \u22c5 2^n) to store all subsets",
            },
        ],
    },
    {
        "title": "Bitwise Arithmetic",
        "intro": "Shift-and-add strategies eliminate expensive arithmetic operators while carefully handling overflow and sign rules.",
        "problems": [
            {
                "title": "Add Two Integers Without the + Operator",
                "file": "Sum_of_Two_Integers.cpp",
                "statement": "Return the sum of two integers a and b without using the + or - operators.",
                "example": "a = 5, b = 7\nOutput: 12",
                "explanation": "XOR adds the bits without carry, while (a & b) << 1 computes the carry bits. Repeating until the carry disappears yields the final sum.",
                "approach": [
                    "Loop while the carry b is non-zero.",
                    "Compute the partial sum with XOR and the carry with AND shifted left by one.",
                    "Assign the partial sum back to a and the shifted carry back to b until the carry becomes zero.",
                ],
                "time_complexity": "O(w) for w-bit integers",
                "space_complexity": "O(1)",
            },
            {
                "title": "Divide Two Integers Without Overflow",
                "file": "Divide_Two_Integers.cpp",
                "statement": "Perform integer division dividend / divisor without using the division operator, truncating toward zero and guarding against overflow.",
                "example": "dividend = 43, divisor = -8\nOutput: -5",
                "explanation": "By repeatedly doubling the divisor with left shifts until it would exceed the remaining dividend, the algorithm subtracts large chunks in logarithmic steps while tracking the quotient with matching multiples.",
                "approach": [
                    "Handle the overflow case where dividend is INT_MIN and divisor is -1 by returning INT_MAX.",
                    "Determine the sign of the result and work with absolute values stored in 64-bit temporaries.",
                    "While the remaining dividend is at least the divisor, shift the divisor left until it would overshoot, subtract it, and accumulate the corresponding multiple in the quotient.",
                    "Apply the computed sign to the quotient before returning.",
                ],
                "time_complexity": "O(log(|dividend|))",
                "space_complexity": "O(1)",
            },
        ],
    },
    {
        "title": "Bitset-Powered Number Theory",
        "intro": "Dense bitsets model primality flags compactly, enabling fast sieves and factor generation.",
        "problems": [
            {
                "title": "Count Primes with a Bitset Sieve",
                "file": "Sieve_of_Erastothenes.cpp",
                "statement": "Given n, count how many prime numbers are strictly less than n using a memory-efficient bitset.",
                "example": "n = 10\nOutput: 4",
                "explanation": "The sieve marks composite numbers by toggling bits in a packed array; unmarked positions correspond to primes.",
                "approach": [
                    "Initialise a bitset large enough to represent odd numbers up to n.",
                    "Iterate through potential primes and mark their multiples as composite by setting the associated bits.",
                    "Count the indices that remain unmarked to obtain the number of primes.",
                ],
                "time_complexity": "O(n log log n)",
                "space_complexity": "O(n / 32)",
            },
            {
                "title": "Prime Factors via Bitset Sieve",
                "file": "Prime_Factor_of_Number.cpp",
                "statement": "Return the list of prime factors of an integer n in ascending order.",
                "example": "n = 84\nOutput: [2, 3, 7]",
                "explanation": "After running a sieve to mark composites, scanning through the bitset reveals the primes that divide n exactly.",
                "approach": [
                    "Build a bitset that flags composite numbers up to n using the sieve of Eratosthenes.",
                    "Iterate through the integers from 2 to n and test whether each candidate remains marked as prime.",
                    "Append primes that divide n evenly to the answer list.",
                ],
                "time_complexity": "O(n log log n)",
                "space_complexity": "O(n / 32)",
            },
            {
                "title": "Enumerate Divisors with Subset Products",
                "file": "All_Divisors_of_Number.cpp",
                "statement": "List every divisor of n by first collecting its prime factors and then multiplying subsets of those primes.",
                "example": "n = 30\nOutput: [1, 2, 3, 6, 5, 10, 15, 30]",
                "explanation": "The routine identifies the prime factors of n using a sieve-backed bitset and then treats each subset of the factors as a divisor by multiplying the selected primes together.",
                "approach": [
                    "Run a sieve to capture prime numbers up to n inside a bit-packed array.",
                    "Gather the primes that divide n exactly and store them in a vector.",
                    "Iterate over all bit masks from 0 to 2^k - 1 (where k is the number of prime factors) and multiply the chosen primes to generate each divisor.",
                    "Collect the generated products; to handle repeated prime powers you would include the prime multiple times.",
                ],
                "time_complexity": "O(n log log n + 2^k)",
                "space_complexity": "O(k)",
            },
        ],
    },
]

for section in categories:
    add_markdown(f"## {section['title']}")
    if section.get("intro"):
        add_markdown(section["intro"])
    for problem in section["problems"]:
        add_problem(problem)

nb = {
    "cells": cells,
    "metadata": {},
    "nbformat": 4,
    "nbformat_minor": 5,
}

OUTPUT.write_text(json.dumps(nb, indent=2))
