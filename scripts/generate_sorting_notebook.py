from __future__ import annotations

import json
from pathlib import Path
import textwrap

ROOT = Path(__file__).resolve().parents[1]
SORTING_DIR = ROOT / "Sorting Algorithms"
OUTPUT = SORTING_DIR / "Sorting_Algorithms_Problems.ipynb"

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
    add_code_from(SORTING_DIR / problem["file"])


add_markdown(
    """
    # Sorting Algorithms Interview Workbook
    """
)

add_markdown(
    """
    Sorting sits at the heart of array and data processing questions. This notebook revisits each sorting
    implementation in the repository with a concise prompt, a worked example, the core idea, and the original C++
    source so you can revise both the reasoning and the code together.
    """
)

add_markdown(
    """
    ## Sorting primer

    - Sorting organises data to unlock binary searches, sweep-line techniques, and clean deduplication.
    - Comparison-based sorts such as bubble, selection, and insertion rely on adjacent swaps or minimum selection.
    - Divide-and-conquer sorts like quick sort partition around a pivot to achieve near-linear performance in practice.
    - Counting, bucket, and radix strategies exploit value ranges to deliver linear-time ordering when applicable.
    """
)

categories: list[dict] = [
    {
        "title": "Elementary Comparison Sorts",
        "intro": (
            "Start with the foundational O(n^2) algorithms that teach how repeated adjacent comparisons gradually build an "
            "ordered array."
        ),
        "problems": [
            {
                "title": "Bubble Sort",
                "file": "BubbleSort.cpp",
                "statement": (
                    "Given an array of integers, repeatedly swap adjacent elements that are out of order until the array becomes "
                    "sorted in non-decreasing order."
                ),
                "example": "Input: arr = [5, 1, 4, 2, 8]\nOutput: [1, 2, 4, 5, 8]",
                "explanation": (
                    "Each outer pass bubbles the largest remaining element to the end of the unsorted range. Early termination is "
                    "possible if a pass performs no swaps."
                ),
                "approach": [
                    "Traverse the array multiple times, swapping adjacent pairs whenever the left value exceeds the right value.",
                    "Track whether any swap occurred during a pass to detect a fully sorted array early.",
                    "After each pass, the sorted suffix grows from the end, so the inner loop can avoid already placed items.",
                ],
                "time_complexity": "O(n^2)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Selection Sort",
                "file": "SelectionSort.cpp",
                "statement": (
                    "Sort an array by repeatedly selecting the smallest element from the unsorted suffix and moving it to the "
                    "front."
                ),
                "example": "Input: arr = [64, 25, 12, 22, 11]\nOutput: [11, 12, 22, 25, 64]",
                "explanation": (
                    "Selecting the global minimum for each position ensures the prefix is sorted after every iteration without "
                    "requiring stability."
                ),
                "approach": [
                    "For each index i, scan the remaining positions to find the smallest value and remember its index.",
                    "Swap that minimum with the element at index i to extend the sorted prefix by one element.",
                    "Repeat until every position has been processed, at which point the array is sorted.",
                ],
                "time_complexity": "O(n^2)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Insertion Sort",
                "file": "InsertionSort.cpp",
                "statement": (
                    "Process the array from left to right, inserting each element into its correct position within the already "
                    "sorted prefix."
                ),
                "example": "Input: arr = [12, 11, 13, 5, 6]\nOutput: [5, 6, 11, 12, 13]",
                "explanation": (
                    "Shifting larger elements to the right while moving backwards through the sorted prefix makes room for the "
                    "current key."
                ),
                "approach": [
                    "Iterate from the second element onward, treating the left side as a sorted prefix.",
                    "Compare the current value with elements to its left, shifting larger entries one step to the right.",
                    "Place the value once the correct spot is found, then continue with the next element.",
                ],
                "time_complexity": "O(n^2) in the worst case, O(n) when already sorted",
                "space_complexity": "O(1)",
            },
        ],
    },
    {
        "title": "Divide and Conquer Sorting",
        "intro": (
            "Leverage recursive partitioning to split the problem into subarrays that are sorted and combined efficiently."
        ),
        "problems": [
            {
                "title": "Quick Sort",
                "file": "QuickSort.cpp",
                "statement": (
                    "Sort an array by partitioning around a pivot so that elements less than or equal to the pivot appear on the "
                    "left and larger elements on the right, then recursively sort both partitions."
                ),
                "example": "Input: arr = [10, 7, 8, 9, 1, 5]\nOutput: [1, 5, 7, 8, 9, 10]",
                "explanation": (
                    "Choosing the last element as the pivot and performing a Lomuto partition positions the pivot at its final "
                    "index before recursing on the left and right segments."
                ),
                "approach": [
                    "Pick a pivot (the implementation uses the last element) and maintain a pointer for the boundary of smaller "
                    "values.",
                    "Traverse the subarray, swapping elements into the smaller partition whenever they do not exceed the pivot.",
                    "Place the pivot after the smaller values and recursively quick sort the two resulting partitions.",
                ],
                "time_complexity": "O(n log n) average, O(n^2) worst case",
                "space_complexity": "O(log n) recursion depth on average",
            },
        ],
    },
    {
        "title": "Linear-Time Sorting Techniques",
        "intro": (
            "When the input values fall within a manageable range or digit structure, counting- and bucket-based strategies "
            "deliver near-linear performance."
        ),
        "problems": [
            {
                "title": "Counting Sort",
                "file": "CountingSort.cpp",
                "statement": (
                    "Given non-negative integers within a known range, count how often each value occurs and rebuild the array in "
                    "sorted order."
                ),
                "example": "Input: arr = [4, 2, 2, 8, 3, 3, 1]\nOutput: [1, 2, 2, 3, 3, 4, 8]",
                "explanation": (
                    "The algorithm allocates a frequency array indexed by value, tallies occurrences, and then writes each value "
                    "back in order according to its count."
                ),
                "approach": [
                    "Scan the input once to determine the maximum value and size of the counting array.",
                    "Increment the frequency bucket for each element to capture multiplicities.",
                    "Iterate through the counts, writing each value the recorded number of times into the result array.",
                ],
                "time_complexity": "O(n + k) where k is the range of values",
                "space_complexity": "O(n + k)",
            },
            {
                "title": "Radix Sort",
                "file": "RadixSort.cpp",
                "statement": (
                    "Sort integers by processing digits from least significant to most significant, applying a stable counting "
                    "sort on each digit position."
                ),
                "example": "Input: arr = [170, 45, 75, 90, 802, 24, 2, 66]\nOutput: [2, 24, 45, 66, 75, 90, 170, 802]",
                "explanation": (
                    "Stable digit-by-digit passes ensure the relative order of equal digits is preserved, so earlier digits remain "
                    "sorted while later digits are processed."
                ),
                "approach": [
                    "Identify the maximum value to know how many digit positions are required.",
                    "For each exponent (1, 10, 100, ...), perform a stable counting sort keyed by the current digit.",
                    "After processing all digit places, the array is sorted lexicographically by digits.",
                ],
                "time_complexity": "O(d * (n + k)) where d is digits and k=10 for base-10",
                "space_complexity": "O(n + k)",
            },
            {
                "title": "Bucket Sort",
                "file": "BucketSort.cpp",
                "statement": (
                    "Distribute elements into a fixed number of buckets covering the value range, sort each bucket individually, "
                    "and concatenate them to obtain the sorted array."
                ),
                "example": "Input: arr = [42, 32, 33, 52, 37, 47, 51]\nOutput: [32, 33, 37, 42, 47, 51, 52]",
                "explanation": (
                    "Mapping values to buckets based on their relative position in the range keeps nearby numbers together so that "
                    "local sorting plus concatenation yields a globally sorted order."
                ),
                "approach": [
                    "Compute the minimum and maximum to understand the distribution and decide how many buckets to use.",
                    "Assign each value to a bucket derived from its offset within the range, then sort buckets individually.",
                    "Concatenate the buckets in order to produce the final sorted array.",
                ],
                "time_complexity": "O(n) on average with evenly distributed data",
                "space_complexity": "O(n)",
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
