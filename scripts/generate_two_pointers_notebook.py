from __future__ import annotations
import json
from pathlib import Path
import textwrap

ROOT = Path(__file__).resolve().parents[1]
TWO_POINTERS_DIR = ROOT / "Two Pointers and SlidingWindow"
OUTPUT = TWO_POINTERS_DIR / "Two_Pointers_and_Sliding_Window_Problems.ipynb"

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
    add_code_from(TWO_POINTERS_DIR / problem["file"])


add_markdown(
    """
    # Two Pointers and Sliding Window Interview Workbook
    """
)

add_markdown(
    """
    Two pointers and sliding windows turn brute-force subarray scans into linear-time passes.
    This notebook gathers every array and string exercise in the repository that relies on the technique so you can revisit the prompt,
    study a representative example, internalise the reasoning, and review the finished C++ implementation without jumping between files.
    """
)

categories: list[dict] = [
    {
        "title": "Foundational Sliding Window Patterns",
        "intro": "Build confidence with classic window expansions that maintain counts, enforce size limits, and optimise segment length.",
        "problems": [
            {
                "title": "Maximise Ones with Limited Zero Flips",
                "file": "Maximum_Consecutive_Ones.cpp",
                "statement": "Given a binary array nums and an integer k, return the length of the longest contiguous subarray that contains at most k zeros.",
                "example": "nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2\nOutput: 6",
                "explanation": "Keep a window that never holds more than k zeros. Its size at any point gives the longest segment ending at the current index where flips stay within budget.",
                "approach": [
                    "Slide a right pointer across the array while counting zeros inside the window.",
                    "Whenever the zero count exceeds k, advance the left pointer and remove zeros until the window is valid again.",
                    "Track the maximum window length seen during the scan and return it at the end.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Fruits into Two Baskets",
                "file": "Fruits_Into_Basket.cpp",
                "statement": "You are given an integer array fruits representing tree types along a road. Starting at any position you may move right, collecting one fruit per tree into two baskets. Each basket can hold only one fruit type. Return the maximum number of fruits you can collect in a single run.",
                "example": "fruits = [1,2,1,2,3,2,2,2]\nOutput: 5",
                "explanation": "Maintain a window containing at most two distinct fruit types. Its length captures the best streak you can harvest without violating the basket constraint.",
                "approach": [
                    "Expand the right pointer, counting fruit frequencies inside an unordered_map.",
                    "If more than two types appear, shrink the window from the left, decrementing counts and erasing any type that drops to zero.",
                    "Update the maximum window size after each expansion to record the best harvest length.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1) average for the hash map",
            },
            {
                "title": "Longest Subarray with Sum Limited by K",
                "file": "Largest_Subarray_Sum_Less_than_Equal_to_K.cpp",
                "statement": "Given an array of non-negative integers and an integer k, find the length of the longest contiguous subarray whose sum is less than or equal to k.",
                "example": "nums = [4,2,1,7,8,1,2,8,1,0], k = 8\nOutput: 4",
                "explanation": "A growing window accumulates values until it violates the sum limit. Shrinking from the left restores feasibility and reveals the best window length along the way.",
                "approach": [
                    "Grow the right pointer, adding each number to a running sum.",
                    "While the sum exceeds k, move the left pointer forward and subtract values until the constraint is satisfied.",
                    "Record the maximum width seen after each adjustment to capture the longest valid subarray.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Maximise Points by Picking from Ends",
                "file": "Maximum_Points_From_N_cards.cpp",
                "statement": "Given an array cardPoints and an integer k, choose exactly k cards from either end of the array to maximise the total score.",
                "example": "cardPoints = [1,2,3,4,5,6,1], k = 3\nOutput: 12",
                "explanation": "Rather than enumerating all end choices, take the first k cards as a baseline and slide a window that swaps cards from the left end with cards from the right end, retaining the best score.",
                "approach": [
                    "Pre-compute the sum of the first k elements as the initial score.",
                    "Iteratively move one card from the left selection to the right end by subtracting from the running sum and adding a card from the opposite side.",
                    "Track the maximum sum encountered during the swap process and return it.",
                ],
                "time_complexity": "O(k)",
                "space_complexity": "O(1)",
            },
        ],
    },
    {
        "title": "Counting Subarrays with Frequency Targets",
        "intro": "Sliding windows also excel at counting subarrays that meet sum or distinctness requirements by comparing at-most totals.",
        "problems": [
            {
                "title": "Count Binary Subarrays with Sum",
                "file": "Binary_Subarray_With_Sum.cpp",
                "statement": "Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum equal to goal.",
                "example": "nums = [1,0,1,0,1], goal = 2\nOutput: 4",
                "explanation": "Counting subarrays with sum \u2264 goal and subtracting those with sum \u2264 goal-1 yields the exact number with sum equal to goal. Each at-most count comes from a window that never exceeds the cap.",
                "approach": [
                    "Write a helper that counts subarrays whose sum is at most target by expanding a window and shrinking whenever the running sum exceeds the target.",
                    "Handle negative targets as a zero count edge case.",
                    "Return helper(goal) minus helper(goal - 1) to isolate the exact-sum total.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Count Nice Subarrays with K Odds",
                "file": "Count_Number_of_Nice_Subarrays.cpp",
                "statement": "Given an integer array nums and an integer k, return the number of subarrays that contain exactly k odd numbers.",
                "example": "nums = [1,1,2,1,1], k = 3\nOutput: 2",
                "explanation": "Treat odd numbers as ones and even numbers as zeros. Counting windows with at most k odds and subtracting those with at most k-1 odds leaves the number with exactly k odds.",
                "approach": [
                    "Convert each value to its parity contribution while maintaining a sliding sum of odds inside the window.",
                    "Shrink from the left whenever the odd count exceeds the target to maintain an at-most tally.",
                    "Return the difference between counts for k and k-1 to obtain the exact total of nice subarrays.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Subarrays with Exactly K Distinct Integers",
                "file": "Subarrays_With_K_Different_Integers.cpp",
                "statement": "Given an integer array nums and an integer k, return the number of subarrays that contain exactly k distinct integers.",
                "example": "nums = [1,2,1,2,3], k = 2\nOutput: 7",
                "explanation": "Counting subarrays with at most k distinct numbers and subtracting the total with at most k-1 distinct numbers isolates those with exactly k unique values.",
                "approach": [
                    "Use an unordered_map to count frequencies while expanding the right pointer.",
                    "When the number of distinct keys exceeds k, increment the left pointer and remove elements until the window is valid.",
                    "Accumulate the size of every valid window to count at-most-k subarrays, then subtract the at-most-(k-1) total.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(k)",
            },
        ],
    },
    {
        "title": "String Window Challenges",
        "intro": "Character windows juggle frequency maps to ensure coverage, uniqueness, or replacement budgets across substrings.",
        "problems": [
            {
                "title": "Longest Substring Without Repeating Characters",
                "file": "Longest_Substring_Without_Repeating_Charecter.cpp",
                "statement": "Given a string s, return the length of the longest substring without repeating characters.",
                "example": "s = \"abcabcbb\"\nOutput: 3",
                "explanation": "A window expands until a duplicate appears. Shrinking from the left removes repeated characters, keeping the window valid and revealing the best length.",
                "approach": [
                    "Store character frequencies in an unordered_map as the right pointer advances.",
                    "When the current character repeats, move the left pointer forward and decrement counts until the duplicate disappears.",
                    "Update the maximum window length after each expansion to capture the best substring.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(min(n, |\u03a3|))",
            },
            {
                "title": "Longest Repeating Character Replacement",
                "file": "Longest_Repeating_Charecter_Replacement.cpp",
                "statement": "Given a string s and an integer k, return the length of the longest substring that can be obtained by replacing at most k characters so that the substring contains only one repeating character.",
                "example": "s = \"AABABBA\", k = 1\nOutput: 4",
                "explanation": "The limiting factor is the most frequent character in the window. As long as replacements needed stay within k, the window can grow; otherwise shrink from the left.",
                "approach": [
                    "Track character counts and the highest frequency seen so far while sliding the right pointer.",
                    "If the window size minus the highest frequency exceeds k, move the left pointer forward and decrement the departing character.",
                    "Keep the best window size observed as the answer.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1) for uppercase alphabet",
            },
            {
                "title": "Minimum Window Substring",
                "file": "Minimum_Window_Substring.cpp",
                "statement": "Given two strings s and t, return the minimum window substring of s that includes every character in t (with multiplicity). If no such substring exists, return an empty string.",
                "example": "s = \"ADOBECODEBANC\", t = \"ABC\"\nOutput: \"BANC\"",
                "explanation": "Expand the window until all requirements are met, then shrink from the left to discard unnecessary characters while maintaining coverage, tracking the smallest valid span.",
                "approach": [
                    "Initialise a frequency map for t and a counter of how many characters are still required.",
                    "Move the right pointer, decrementing the requirement for each encountered character.",
                    "Once all characters are covered, contract the left pointer while the window remains valid to seek the minimum length and update the answer.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(|\u03a3|)",
            },
            {
                "title": "Count Substrings Containing a, b, and c",
                "file": "Number_of_Substrings_Containing_all_Three_Charecters.cpp",
                "statement": "Given a string s consisting only of the characters 'a', 'b', and 'c', return the number of substrings that contain at least one occurrence of each character.",
                "example": "s = \"abcabc\"\nOutput: 10",
                "explanation": "For each ending index, the earliest start that yields a valid substring is the smallest last-seen position among the three characters. Every earlier start also forms a valid substring.",
                "approach": [
                    "Scan with a right pointer while tracking the most recent index where 'a', 'b', and 'c' appeared.",
                    "After processing each character, add the smallest of the three last-seen indices plus one to the answer to count new substrings ending at that position.",
                    "Continue until the right pointer reaches the end of the string.",
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
