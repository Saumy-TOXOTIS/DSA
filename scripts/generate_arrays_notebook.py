from __future__ import annotations

import json
from pathlib import Path
import textwrap

ROOT = Path(__file__).resolve().parents[1]
ARRAYS_DIR = ROOT / "Arrays"
OUTPUT = ARRAYS_DIR / "Arrays_Problems.ipynb"

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
    text += (
        f"**Complexity:** Time {problem['time_complexity']}, "
        f"Space {problem['space_complexity']}."
    )
    add_markdown(text)
    add_code_from(ARRAYS_DIR / problem["file"])


add_markdown(
    """
# Arrays Interview Workbook
"""
)
add_markdown(
    """
This notebook collates every array-focused challenge from the repository. Each section explains the scenario, walks through a
worked example, records the reasoning that leads to the solution, and embeds the original C++ source so you can revise the pat
tern alongside the implementation.
"""
)
add_markdown(
    """
## Arrays primer

- Arrays offer contiguous storage that enables O(1) random access but requires careful index management to avoid bounds errors.
- Prefix/suffix sweeps, hash maps, and sorting unlock many counting and optimisation tricks on arrays.
- Look for opportunities to compress state—two-pointer passes, rolling products, or maintaining running extrema keep solutions
linear.
- When a task asks for reconstruction, ensure the output ordering satisfies the stated constraints before coding the template.
"""
)

categories: list[dict] = [
    {
        "title": "Frequency Checks and Running Products",
        "intro": (
            "Start with staple interview questions that emphasise hash-based duplicate detection and the prefix/suffix"
            " pattern for multiplicative arrays."
        ),
        "problems": [
            {
                "title": "Contains Duplicate",
                "file": "Contains_Duplicate.cpp",
                "statement": (
                    "Given an integer array, determine whether any value appears at least twice. Return true if a duplicate"
                    " exists and false otherwise."
                ),
                "example": "nums = [1, 2, 3, 1]\nOutput: true",
                "explanation": (
                    "Sweeping through the numbers while tracking frequency in a hash map lets us report a duplicate the"
                    " moment a count reaches two."
                ),
                "approach": [
                    "Iterate across the array and increment the count for each value inside an unordered_map.",
                    "As soon as a count is at least two, return true because a duplicate has been found.",
                    "If the loop finishes without triggering the early return, no duplicates were encountered.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n) for the hash map",
            },
            {
                "title": "Product of Array Except Self",
                "file": "Product_of_Array_Except_Itself.cpp",
                "statement": (
                    "For an integer array nums, build a result array where result[i] equals the product of every element"
                    " except nums[i] without using division."
                ),
                "example": "nums = [1, 2, 3, 4]\nOutput: [24, 12, 8, 6]",
                "explanation": (
                    "Carrying the prefix product to each position and then sweeping from the right with suffix products"
                    " multiplies together all values except the current index."
                ),
                "approach": [
                    "Store the running prefix product for each index before visiting it in the first pass.",
                    "Sweep from the end maintaining a suffix product so every entry is multiplied by values on the right.",
                    "Return the populated array once both passes complete.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1) extra beyond the output",
            },
        ],
    },
    {
        "title": "Array Normalisation Strategies",
        "intro": (
            "These problems equalise array values using arithmetic observations that convert seemingly expensive operations"
            " into direct formulas."
        ),
        "problems": [
            {
                "title": "Minimum Moves to Equal Array Elements",
                "file": "Minimum_Moves_to_Equal_Array_Elements.cpp",
                "statement": (
                    "You may increment n - 1 elements by 1 during each move. Find the minimum moves needed to make every"
                    " array element equal."
                ),
                "example": "nums = [1, 2, 3]\nOutput: 3",
                "explanation": (
                    "Incrementing everyone except one element is equivalent to decrementing that element, so all numbers"
                    " catch up to the minimum by the total difference."
                ),
                "approach": [
                    "Identify the minimum element because all numbers must effectively reduce to it.",
                    "Sum the difference between each value and the minimum to count how many decrements are required.",
                    "Return the accumulated difference as the answer.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Minimum Moves to Equal Array Elements II",
                "file": "Minimum_Moves_to_Equal_Array_Elements_II.cpp",
                "statement": (
                    "In one move you may increment or decrement any element by 1. Determine the minimum moves to make every"
                    " element equal."
                ),
                "example": "nums = [1, 2, 3]\nOutput: 2",
                "explanation": (
                    "The sum of absolute deviations is minimised at the median, so aligning everything to the median uses"
                    " the fewest steps."
                ),
                "approach": [
                    "Sort the array to expose the median element.",
                    "Choose the median as the target value that minimises absolute deviations.",
                    "Add up |num - median| for every value to compute the minimal move count.",
                ],
                "time_complexity": "O(n log n) due to sorting",
                "space_complexity": "O(1) extra",
            },
        ],
    },
    {
        "title": "Constructive and Ordering Tricks",
        "intro": (
            "Ordering the array to satisfy bespoke constraints often depends on clever patterns and custom comparators."
        ),
        "problems": [
            {
                "title": "Beautiful Arrangement II",
                "file": "Beautiful_Arrangement.cpp",
                "statement": (
                    "Given n and k, construct an array of 1..n such that the set of absolute differences between consecutive"
                    " elements contains exactly k distinct values."
                ),
                "example": "n = 5, k = 2\nOutput: [1, 2, 5, 3, 4]",
                "explanation": (
                    "Placing the first n - k numbers sequentially then zig-zagging the remaining range from both ends"
                    " produces k unique step sizes."
                ),
                "approach": [
                    "Append the ascending prefix 1 through n - k to guarantee plenty of repeated differences of 1.",
                    "Alternate between the high and low pointers across the final k + 1 numbers to create new gap sizes.",
                    "Stop when the pointers meet, emitting the remaining middle value if the range length is odd.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1) extra beyond the output",
            },
            {
                "title": "Largest Number",
                "file": "Largest_Number.cpp",
                "statement": (
                    "Rearrange a list of non-negative integers so their concatenation yields the largest possible number"
                    " when read as a string."
                ),
                "example": "nums = [3, 30, 34, 5, 9]\nOutput: \"9534330\"",
                "explanation": (
                    "Comparing numbers by concatenated order (ab vs ba) ensures the sort places digits that form larger"
                    " prefixes earlier."
                ),
                "approach": [
                    "Convert each integer to a string so concatenation comparisons are straightforward.",
                    "Sort the strings with a custom comparator that prefers a + b over b + a when it yields a larger value.",
                    "Handle the all-zero edge case by returning \"0\" instead of a string of zeroes.",
                ],
                "time_complexity": "O(n log n) string sort",
                "space_complexity": "O(n) for the string list",
            },
        ],
    },
    {
        "title": "Prefix Sums and Hash Maps",
        "intro": (
            "Tracking running sums with hash maps unlocks linear-time solutions for subarray queries even when negatives"
            " appear."
        ),
        "problems": [
            {
                "title": "Subarray Sum Equals K",
                "file": "Algorithms/Subarray_Sum_Equals_K.cpp",
                "statement": (
                    "Count the number of continuous subarrays whose elements sum to k. The array may contain positive"
                    " numbers, negatives, and zeros."
                ),
                "example": "nums = [1, 1, 1], k = 2\nOutput: 2",
                "explanation": (
                    "When the running sum minus k has been seen before, the subarrays between those indices sum to k."
                ),
                "approach": [
                    "Maintain a hash map of prefix sums to their frequency while traversing the array.",
                    "For each new prefix sum, add the count of (prefix - k) to the answer because those endpoints form k-sum ranges.",
                    "Increment the frequency of the current prefix sum before moving on.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n) for the prefix map",
            },
            {
                "title": "Longest Subarray with Sum K",
                "file": "Algorithms/Longest_Subarrray_with_Sum_k.cpp",
                "statement": (
                    "Find the length of the longest contiguous subarray whose sum equals k. Values can be positive,"
                    " negative, or zero."
                ),
                "example": "nums = [1, -1, 5, -2, 3], k = 3\nOutput: 4",
                "explanation": (
                    "Recording the earliest index of each prefix sum lets us compute how far back we can stretch while"
                    " preserving a sum of k."
                ),
                "approach": [
                    "Accumulate the running sum while iterating over the array.",
                    "If the sum equals k, update the best length with the prefix up to the current index.",
                    "When (sum - k) exists in the map, the subarray between that earlier index and the current index forms a k-sum segment.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n) for the prefix map",
            },
        ],
    },
    {
        "title": "Kadane's Patterns",
        "intro": (
            "Kadane-style dynamic tracking generalises to both additive and multiplicative subarray optimisation problems."
        ),
        "problems": [
            {
                "title": "Maximum Sum Subarray (Kadane's Algorithm)",
                "file": "Algorithms/Kadane_Algorithm_Maximum_Sum_of_Subarray.cpp",
                "statement": (
                    "Given an array of integers, compute the maximum possible sum of any non-empty contiguous subarray."
                ),
                "example": "nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]\nOutput: 6",
                "explanation": (
                    "Tracking a running sum that resets when it drops below zero ensures we only extend profitable prefixes"
                    " while scanning."
                ),
                "approach": [
                    "Maintain the current sum and update it by adding the next value in the array.",
                    "Whenever the current sum becomes negative, reset it to zero because continuing would only hurt future totals.",
                    "Track the maximum sum seen across the traversal and print it at the end.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Maximum Product Subarray",
                "file": "Algorithms/Kadane_Algorithm_Maximum_Product_of_Subarray.cpp",
                "statement": (
                    "Find the maximum product of a contiguous subarray within an integer array that may contain negatives and zeros."
                ),
                "example": "nums = [2, 3, -2, 4]\nOutput: 6",
                "explanation": (
                    "Because multiplying by a negative swaps maxima and minima, we track both running extremes before"
                    " updating the answer."
                ),
                "approach": [
                    "Store the maximum and minimum product ending at the current index before the update.",
                    "Multiply the current value into both extremes and compute the new candidates using std::max and std::min.",
                    "Record the largest product encountered as the traversal proceeds.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
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
