from __future__ import annotations
import json
from pathlib import Path
import textwrap

ROOT = Path(__file__).resolve().parents[1]
STACK_QUEUE_DIR = ROOT / "Stack and Queue"
OUTPUT = STACK_QUEUE_DIR / "Stack_and_Queue_Problems.ipynb"

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
    add_code_from(STACK_QUEUE_DIR / problem["file"])


add_markdown(
    """
    # Stack and Queue Interview Workbook
    """
)

add_markdown(
    """
    Stacks, queues, and deques sit at the heart of many interview classics.
    This notebook curates every stack and queue exercise in the repository so you can revise the prompt,
    walk through a representative example, review the guiding idea, and study the C++ implementation in one place.
    """
)

categories: list[dict] = [
    {
        "title": "Stack Fundamentals and Simulation",
        "intro": "Build intuition for stack-based validation and state simulation problems before moving on to advanced patterns.",
        "problems": [
            {
                "title": "Validate Balanced Parentheses",
                "file": "Balanced_Parentheses.cpp",
                "statement": "Given a string containing the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. A string is valid if open brackets are closed by the same type of bracket and in the correct order.",
                "example": "s = \"{[()]}\"\nOutput: true",
                "explanation": "The algorithm pushes opening brackets onto a stack and matches them against closing brackets using a lookup map. Any mismatch or premature closing bracket invalidates the string, and the stack must be empty when processing ends.",
                "approach": [
                    "Create a mapping from each closing bracket to the expected opening bracket.",
                    "Iterate through the string, pushing every opening bracket onto the stack as it appears.",
                    "For a closing bracket, ensure the stack is non-empty and the top element matches the required opening bracket; otherwise return false immediately.",
                    "After processing all characters, confirm the stack is empty to verify that every opening bracket was closed.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Design a Minimum-Tracking Stack",
                "file": "Implement_Min_Stack.cpp",
                "statement": "Implement a stack that supports push, pop, top, and retrieving the minimum element in constant time.",
                "example": "Operations:\npush(2)\npush(0)\npush(3)\npush(0)\ngetMin() -> 0\npop()\ngetMin() -> 0\npop()\ngetMin() -> 0\npop()\ngetMin() -> 2",
                "explanation": "Each stack node records both its value and the minimum seen up to that point. The current minimum is always stored alongside the top node, allowing each operation to run in constant time.",
                "approach": [
                    "Store pairs of (value, current minimum) inside the stack structure.",
                    "When pushing, compute the new minimum as the smaller of the incoming value and the previous minimum, then push the pair.",
                    "Pop operations simply discard the top pair, automatically exposing the previous minimum.",
                    "top() returns the latest value, and getMin() returns the minimum stored with that node.",
                ],
                "time_complexity": "O(1) per operation",
                "space_complexity": "O(n)",
            },
            {
                "title": "Simulate Asteroid Collisions",
                "file": "Asteroid_Collision.cpp",
                "statement": "Given an array of integers representing asteroids moving along a line, where the absolute value is the size and the sign is the direction (positive moves right, negative moves left), return the state after all collisions. Smaller asteroids explode; equal-sized asteroids destroy each other.",
                "example": "asteroids = [5, 10, -5]\nOutput: [5, 10]",
                "explanation": "The implementation tracks indices of right-moving asteroids on a stack. When a left-moving asteroid arrives, it repeatedly collides with right-moving asteroids until it either explodes, destroys an equal-sized asteroid, or survives because no right-moving rocks remain in front of it.",
                "approach": [
                    "Traverse the list and push indices of right-moving asteroids onto a stack.",
                    "When a left-moving asteroid is encountered, pop any smaller right-moving asteroids from the stack and mark them as destroyed.",
                    "If an asteroid of equal magnitude is found, mark both as destroyed and remove the right-moving asteroid from the stack.",
                    "Collect every asteroid still marked as alive into the output list at the end of the scan.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n)",
            },
        ],
    },
    {
        "title": "Monotonic Stack for Next/Previous Comparisons",
        "intro": "Monotonic stacks efficiently answer next and previous greater-or-smaller queries and power several greedy optimisations.",
        "problems": [
            {
                "title": "Next Greater Element I",
                "file": "Next_Greater_Element.cpp",
                "statement": "For each element in nums1, find the next greater element appearing to its right in nums2. If it does not exist, return -1.",
                "example": "nums1 = [4, 1, 2]\nnums2 = [1, 3, 4, 2]\nOutput: [-1, 3, -1]",
                "explanation": "Scanning nums2 from right to left maintains a decreasing stack of candidates. A map records each value's next greater element, and a final pass over nums1 replaces each query with the mapped answer.",
                "approach": [
                    "Initialise a stack with a sentinel -1 to represent missing next greater elements.",
                    "Iterate through nums2 from right to left, popping any stack values less than the current element.",
                    "After the pops, the stack top holds the next greater value (or -1); record it in a map and push the current element.",
                    "Build the answer for nums1 by looking up each value's mapped next greater element.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(m)",
            },
            {
                "title": "Next Greater Element II (Circular Array)",
                "file": "Next_Greater_Element_II.cpp",
                "statement": "Given a circular array nums, compute the next greater element for every index, wrapping around to the beginning of the array when necessary.",
                "example": "nums = [1, 2, 1]\nOutput: [2, -1, 2]",
                "explanation": "The algorithm preloads a decreasing stack with a single backward pass, then performs a second pass to assign answers, continually discarding values that are not greater than the current element.",
                "approach": [
                    "Traverse the array from right to left once to seed the stack with elements in decreasing order.",
                    "Perform a second backward traversal, popping stack elements that are less than or equal to the current value.",
                    "If the stack is non-empty, record its top as the next greater element for the current index; otherwise record -1.",
                    "Push the current value so earlier elements can observe it when their turn arrives.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Previous Smaller Element",
                "file": "Previous_Smaller_Element.cpp",
                "statement": "For each position in an array, find the value of the nearest smaller element to its left. If no such element exists, return -1 for that index.",
                "example": "nums = [4, 5, 2, 10, 8]\nOutput: [-1, 4, -1, 2, 2]",
                "explanation": "A monotonic increasing stack keeps track of potential previous candidates. Whenever a new number arrives, larger or equal values are popped until the stack exposes the nearest smaller value.",
                "approach": [
                    "Maintain a stack that stores values in strictly increasing order from bottom to top.",
                    "For each number, pop stack entries that are greater than or equal to the current value.",
                    "After the pops, if the stack is non-empty, its top is the nearest smaller element; otherwise record -1.",
                    "Push the current value for future indices to reference.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Online Stock Span",
                "file": "Stock_Span_Problem.cpp",
                "statement": "Design a data structure that, for each incoming stock price, returns the number of consecutive days (including today) the price has been less than or equal to today's price.",
                "example": "prices = [100, 80, 60, 70, 60, 75, 85]\nOutput: [1, 1, 1, 2, 1, 4, 6]",
                "explanation": "The stack stores pairs of (price, span). When a new price arrives, the structure collapses any weaker prices beneath it, accumulating their spans so the final answer can be returned in constant time.",
                "approach": [
                    "For each query price, start its span at one (covering the current day).",
                    "While the stack top has a price less than or equal to the new price, pop it and add its span to the running total.",
                    "Push the current price along with the aggregated span onto the stack.",
                    "Return the computed span as the answer for the query.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Remove K Digits for the Smallest Number",
                "file": "Remove_K_Digits.cpp",
                "statement": "Given a non-negative integer num represented as a string and an integer k, remove k digits from the number so that the new number is the smallest possible.",
                "example": "num = \"1432219\", k = 3\nOutput: 1219",
                "explanation": "A monotonic increasing stack of digits guarantees that any higher digit preceding a smaller digit will be removed first. Leading zeros are skipped, and leftover removals trim digits from the end.",
                "approach": [
                    "Iterate through each digit, skipping leading zeros when the stack is empty.",
                    "While k is positive and the stack top digit is greater than the current digit, pop the stack and decrement k.",
                    "Push the current digit, ensuring the structure stays non-decreasing.",
                    "If removals remain after scanning, pop from the stack until k reaches zero, then build the result in reverse order.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n)",
            },
        ],
    },
    {
        "title": "Monotonic Stack Range Aggregations",
        "intro": "These problems compute contributions from every index by measuring how far it can extend before a smaller or greater value blocks it.",
        "problems": [
            {
                "title": "Largest Rectangle in a Histogram",
                "file": "Largest_Rectangle_in_Histogram.cpp",
                "statement": "Given an array of bar heights representing a histogram, return the area of the largest rectangle that can be formed within the histogram.",
                "example": "heights = [2, 1, 5, 6, 2, 3]\nOutput: 10",
                "explanation": "The solution records each bar's nearest smaller element on both sides. The width of the rectangle contributed by each bar is determined by these boundaries, allowing the algorithm to maximise area efficiently.",
                "approach": [
                    "Sweep from left to right with a stack to compute the index of the next smaller element for every bar.",
                    "During the same pass, capture the previous smaller index for each bar once the stack is non-empty.",
                    "For each bar, calculate the rectangle width using the two boundaries and update the maximum area.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Maximal Rectangle in a Binary Matrix",
                "file": "Maximal_Rectangle.cpp",
                "statement": "Given a binary matrix filled with 0s and 1s, find the largest rectangular area containing only 1s.",
                "example": "matrix =\n[\n  [\"1\",\"0\",\"1\",\"0\",\"0\"],\n  [\"1\",\"0\",\"1\",\"1\",\"1\"],\n  [\"1\",\"1\",\"1\",\"1\",\"1\"],\n  [\"1\",\"0\",\"0\",\"1\",\"0\"]\n]\nOutput: 6",
                "explanation": "Each row is treated as the base of a histogram whose heights count consecutive 1s above it. The histogram solver from the previous problem is then applied to every row to keep track of the best rectangle.",
                "approach": [
                    "Precompute column-wise heights representing consecutive ones ending at each row.",
                    "For each row, feed the height array into the histogram routine to compute the largest rectangle that uses that row as its base.",
                    "Track the overall maximum area across all rows and return it at the end.",
                ],
                "time_complexity": "O(rows * cols)",
                "space_complexity": "O(rows * cols)",
            },
            {
                "title": "Sum of Subarray Minimums",
                "file": "Sum_of_Subarray_Minimum.cpp",
                "statement": "For an integer array, compute the sum of the minimum element of every contiguous subarray. Return the result modulo 1e9 + 7.",
                "example": "arr = [3, 1, 2, 4]\nOutput: 17",
                "explanation": "Two monotonic stacks locate the next and previous smaller elements for each index. These spans count how many subarrays adopt the current value as their minimum contribution.",
                "approach": [
                    "Find the next strictly smaller element index for every position using a monotonic stack.",
                    "Find the previous smaller-or-equal index with another stack to avoid double counting.",
                    "Multiply the distances to the boundaries to determine the number of subarrays where the element is the minimum.",
                    "Accumulate the contributions under modulo arithmetic to build the final answer.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Sum of Subarray Maximums",
                "file": "Sum_of_Subarray_Maximum.cpp",
                "statement": "Given an integer array, compute the sum of the maximum element of every contiguous subarray. Return the result modulo 1e9 + 7.",
                "example": "arr = [1, 3, 2]\nOutput: 15",
                "explanation": "The implementation mirrors the minimum-sum technique but inverts the comparisons to locate larger blocking elements, counting how many subarrays treat the current value as their maximum.",
                "approach": [
                    "Use a decreasing stack to record each index's next greater element (strictly greater).",
                    "Use another stack to record the previous greater-or-equal index, preventing over-counting identical values.",
                    "Combine the left and right spans to count the subarrays where the element is the maximum.",
                    "Add each weighted contribution under the required modulo to obtain the final total.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Sum of Subarray Ranges",
                "file": "Sum_of_Subarray_Ranges.cpp",
                "statement": "For an integer array, return the sum of the ranges (maximum minus minimum) of every contiguous subarray. Use modulo arithmetic as defined in the implementation.",
                "example": "nums = [1, 2, 3]\nOutput: 4",
                "explanation": "Range sums equal the total contribution of maxima minus the total contribution of minima. Four monotonic passes compute the necessary next and previous smaller/greater indices to evaluate both parts.",
                "approach": [
                    "Compute next and previous smaller indices to measure how often each element acts as a subarray minimum.",
                    "Compute next and previous greater indices to measure how often each element acts as a subarray maximum.",
                    "Accumulate the weighted minima and maxima separately using modulo arithmetic.",
                    "Return the difference between the two totals to obtain the sum of ranges.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n)",
            },
        ],
    },
    {
        "title": "Queues, Deques, and Two-Pointer Optimisations",
        "intro": "Windowing problems and elimination games often rely on specialised queue-like structures or bidirectional scans to stay linear.",
        "problems": [
            {
                "title": "Sliding Window Maximum",
                "file": "Sliding_Window_Maximum.cpp",
                "statement": "Given an array nums and an integer k, return the maximum element in every contiguous subarray of size k.",
                "example": "nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3\nOutput: [3, 3, 5, 5, 6, 7]",
                "explanation": "A deque of indices stores candidates in decreasing order. Out-of-window indices are removed from the front, and any smaller trailing indices are pruned so the deque front always holds the current maximum.",
                "approach": [
                    "Iterate through the array once, removing indices that fall out of the sliding window from the front of the deque.",
                    "While the deque's back holds values less than or equal to the current element, pop them to maintain decreasing order.",
                    "Push the current index, and once the first full window is formed, record the value at the deque front as the maximum.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(k)",
            },
            {
                "title": "Trapping Rain Water",
                "file": "Trapping_Rainwater.cpp",
                "statement": "Given non-negative integers representing an elevation map, compute how much water it can trap after raining.",
                "example": "height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]\nOutput: 6",
                "explanation": "The code precomputes suffix maxima and tracks a running prefix maximum while scanning from left to right. Each bar can trap water equal to the difference between the smaller of the two maxima and its own height, floored at zero.",
                "approach": [
                    "Build an array of suffix maxima so each index knows the tallest bar to its right.",
                    "Maintain the running maximum height seen so far while iterating from left to right.",
                    "At each position, compute the limiting height as the minimum of the left and right maxima and add any positive difference between that limit and the current height to the total.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Find the Celebrity",
                "file": "The_Celebrity_Problem.cpp",
                "statement": "Given a matrix matrix where matrix[i][j] == 1 means person i knows person j, determine whether a celebrity exists (someone known by everyone else who knows nobody). Return the celebrity's index or -1 if none exists.",
                "example": "matrix =\n[\n  [0, 1, 1],\n  [0, 0, 0],\n  [0, 1, 0]\n]\nOutput: 1",
                "explanation": "Two pointers eliminate non-celebrity candidates by comparing the knowledge relationship at each step. The surviving candidate is then validated by checking that they know nobody and are known by everyone else.",
                "approach": [
                    "Start with two indices at the beginning and end of the list of people.",
                    "If the top index knows the bottom index, discard the top index; if the bottom index knows the top, discard the bottom; otherwise discard both.",
                    "Once a single candidate remains, verify their row has no outgoing edges and their column has edges from every other person.",
                    "Return the candidate index if validation succeeds, otherwise return -1.",
                ],
                "time_complexity": "O(n + m)",
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
