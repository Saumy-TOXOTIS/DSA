from __future__ import annotations

import json
from pathlib import Path
import textwrap

ROOT = Path(__file__).resolve().parents[1]
BINARY_SEARCH_DIR = ROOT / "Binary Search"
OUTPUT = BINARY_SEARCH_DIR / "Binary_Search_Problems.ipynb"

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
    add_code_from(BINARY_SEARCH_DIR / problem["file"])


add_markdown(
    """
# Binary Search Interview Workbook
"""
)
add_markdown(
    """
This notebook consolidates every binary-search based challenge in the repository. It opens with a refresher on the
pattern—identifying sorted structure or a monotonic decision function—before diving into variations on rotated arrays,
multidimensional grids, and answer-space search. Each section captures the prompt, a guiding example, high-level
reasoning, and the original C++ implementation so you can revise both theory and code together.
"""
)

categories: list[dict] = [
    {
        "title": "Binary Search Essentials in One Dimension",
        "intro": (
            "Warm up with classic utilities that rely on the monotonicity of a sorted array—finding elements, locating "
            "bounds, and turning comparisons into index arithmetic."
        ),
        "problems": [
            {
                "title": "Search for a Target",
                "file": "Binary Search in 1D Array/Find_x_in_Sorted_Array.cpp",
                "statement": "Given a sorted array of distinct integers, return the index of a target value or -1 when it is absent.",
                "example": "nums = [-1,0,3,5,9,12], target = 9\nOutput: 4",
                "explanation": "With the numbers ordered, the predicate `nums[mid] >= target` is monotonic, allowing us to shrink the search interval until the leftmost candidate is checked.",
                "approach": [
                    "Maintain a half-open search range `[left, right)` and repeatedly cut it in half.",
                    "When `nums[mid]` is large enough, discard the right half; otherwise advance `left`.",
                    "After the loop, verify that `left` is in bounds and equals the target before returning it.",
                ],
                "time_complexity": "O(log n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Search Insert Position",
                "file": "Binary Search in 1D Array/Search_Insert_Position.cpp",
                "statement": "Locate the index of a target in a sorted array or the position where it should be inserted to maintain order.",
                "example": "nums = [1,3,5,6], target = 5\nOutput: 2",
                "explanation": "Binary search keeps narrowing the window until the closest element remains. Comparing that element to the target reveals whether to insert before or after it.",
                "approach": [
                    "Binary search while tracking the last midpoint examined.",
                    "If the value at `left` equals the target, return it immediately.",
                    "Otherwise, compare `nums[left]` to the target to decide whether insertion belongs at `left` or `left + 1`.",
                ],
                "time_complexity": "O(log n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "First and Last Occurrence of a Target",
                "file": "Binary Search in 1D Array/Find_the_first_or_last_occurrence_of_a_given_number_in_a_sorted_array.cpp",
                "statement": "Return the first and last indices of a target value in a sorted array; report -1 when the target never appears.",
                "example": "nums = [5,7,7,8,8,10], target = 8\nOutput: [3,4]",
                "explanation": "Two binary searches—one biased left, one biased right—leveraging the monotonic predicate `nums[mid] == target` give the extremes in logarithmic time.",
                "approach": [
                    "Run a binary search that, upon finding the target, continues moving `high` left to capture the first index.",
                    "Repeat symmetrically, pushing `low` right to find the last index.",
                    "Combine the two answers in a pair.",
                ],
                "time_complexity": "O(log n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Lower and Upper Bound",
                "file": "Binary Search in 1D Array/Implement_lower_and_upper_bound.cpp",
                "statement": "Implement `lower_bound` and `upper_bound` for a sorted array: the first index not less than, and the first index greater than, a target value.",
                "example": "arr = [1,2,4,4,5], target = 4\nOutput: lower_bound = 2, upper_bound = 4",
                "explanation": "Because the predicate \"value ≥ target\" flips exactly once, binary search can pinpoint where each bound belongs by favouring the left or right half.",
                "approach": [
                    "Binary search while tracking the best candidate index seen so far.",
                    "For `lower_bound`, move left whenever `arr[mid]` satisfies the predicate, storing the index.",
                    "For `upper_bound`, flip the comparison so the algorithm skips past equal elements before returning.",
                ],
                "time_complexity": "O(log n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Floor and Ceil in a Sorted Array",
                "file": "Binary Search in 1D Array/Floor_and_Ceil_in_Sorted_Array.cpp",
                "statement": "Given a sorted array, return the indices of the floor (greatest value ≤ x) and ceil (smallest value ≥ x) for a query x.",
                "example": "arr = [2,4,6,8,10], x = 7\nOutput: floor index = 2 (value 6), ceil index = 3 (value 8)",
                "explanation": "Both floor and ceil queries rely on favouring the side of the array that still has a chance to contain a valid answer, updating the candidate index while shrinking the window.",
                "approach": [
                    "Maintain two binary searches—one that moves right on success to seek a larger floor, and one that moves left to tighten the ceil.",
                    "Track the last index satisfying the predicate in each search before the pointers cross.",
                    "Return the stored indices (or -1 if no candidate exists).",
                ],
                "time_complexity": "O(log n)",
                "space_complexity": "O(1)",
            },
        ],
    },
    {
        "title": "Binary Search Tricks on 1D Patterns",
        "intro": (
            "Once you are comfortable slicing arrays, binary search doubles as a tool for locating structural features such as "
            "peaks or the lone element that violates pairing patterns."
        ),
        "problems": [
            {
                "title": "Find Peak Element",
                "file": "Binary Search in 1D Array/Find_Peek_Element.cpp",
                "statement": "Return any index i where nums[i] is strictly greater than its neighbours in an array of length at least one.",
                "example": "nums = [1,2,3,1]\nOutput: 2",
                "explanation": "Comparing the midpoint with its neighbours reveals which half contains a peak: if the slope rises to the right, a peak must exist there; otherwise the left half harbours one.",
                "approach": [
                    "Use binary search on indices, checking midpoints against adjacent values.",
                    "When the slope is rising to the right, shift `low` to `mid + 1`; otherwise move `high` left.",
                    "Stop when the search window converges on a peak index and return it.",
                ],
                "time_complexity": "O(log n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Single Element in a Sorted Array",
                "file": "Binary Search in 1D Array/Single_Element_in_Sorted_Array.cpp",
                "statement": "In a sorted array where every element appears exactly twice except for one, find the singleton.",
                "example": "nums = [1,1,2,3,3,4,4,8,8]\nOutput: 2",
                "explanation": "Before the unique element, pairs start at even indices; after it, pairs start at odd indices. Binary search exploits this parity shift to discard half the array each step.",
                "approach": [
                    "Pick midpoints and compare them to neighbours to determine which half contains the parity violation.",
                    "If the duplicate pair straddles mid, shrink the side whose length remains even.",
                    "Repeat until the search narrows to the single remaining index.",
                ],
                "time_complexity": "O(log n)",
                "space_complexity": "O(1)",
            },
        ],
    },
    {
        "title": "Binary Search on Rotated Arrays",
        "intro": (
            "Rotated sorted arrays maintain two sorted segments. By comparing the midpoint with the boundaries you can determine "
            "which portion to keep and still retain logarithmic performance."
        ),
        "problems": [
            {
                "title": "Minimum in Rotated Sorted Array",
                "file": "Binary Search in 1D Array/Find_Minimum_in_Rotated_Sorted_Array.cpp",
                "statement": "Find the minimum element in a rotated ascending array with no duplicates.",
                "example": "nums = [4,5,6,7,0,1,2]\nOutput: 0",
                "explanation": "The array consists of an ascending prefix and suffix. Whenever the mid element is smaller than the left boundary we have crossed the rotation pivot and can tighten the right side; otherwise the left side remains sorted and may contain the minimum.",
                "approach": [
                    "Binary search while tracking the smallest value seen so far.",
                    "If `nums[mid]` is less than `nums[low]`, record it and move `high` left because the pivot lies to the left.",
                    "Otherwise update the candidate with `nums[low]` and shift `low` right to skip the sorted prefix.",
                ],
                "time_complexity": "O(log n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Count Rotations in a Sorted Array",
                "file": "Binary Search in 1D Array/How_many_times_Array_been_Rotated.cpp",
                "statement": "Given a rotated ascending array, compute how many positions it was rotated—equivalently, return the index of the minimum element.",
                "example": "nums = [15,18,2,3,6,12]\nOutput: 2",
                "explanation": "Tracking the smallest element encountered while steering the binary search toward the unsorted half reveals the rotation count.",
                "approach": [
                    "Initialise the answer to a sentinel and perform binary search on the array.",
                    "Whenever `nums[mid]` is less than the left boundary, update the best answer to `mid` and move left.",
                    "Otherwise update the candidate with `low` and move right to explore the rotated tail.",
                ],
                "time_complexity": "O(log n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Search in Rotated Sorted Array I",
                "file": "Binary Search in 1D Array/Search_in_Rotated_Sorted_Array_I.cpp",
                "statement": "Return the index of a target in a rotated sorted array without duplicates, or -1 if absent.",
                "example": "nums = [4,5,6,7,0,1,2], target = 0\nOutput: 4",
                "explanation": "Each midpoint belongs to either the sorted left half or the sorted right half. Checking which half is sorted and whether the target lies inside it lets us discard the other half.",
                "approach": [
                    "Binary search, identifying whether `nums[low..mid]` is sorted or `nums[mid..high]` is sorted.",
                    "If the target falls into the sorted segment, move the opposite boundary inward.",
                    "Otherwise, search the other half until the target is found or the window collapses.",
                ],
                "time_complexity": "O(log n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Search in Rotated Sorted Array II",
                "file": "Binary Search in 1D Array/Search_in_Rotated_Sorted_Array_II.cpp",
                "statement": "Determine whether a target exists in a rotated sorted array that may contain duplicates.",
                "example": "nums = [2,5,6,0,0,1,2], target = 0\nOutput: true",
                "explanation": "Duplicates blur which half is sorted, but by trimming equal endpoints we eventually restore a situation where one half is ordered and can be checked with the standard logic.",
                "approach": [
                    "While the window is valid, compute the midpoint and compare it to the target.",
                    "When endpoints equal the midpoint, shrink both sides to skip duplicates.",
                    "Otherwise, determine the sorted half and keep or discard it depending on whether it can contain the target.",
                ],
                "time_complexity": "O(log n) in the average case, O(n) in the worst case when many duplicates exist",
                "space_complexity": "O(1)",
            },
        ],
    },
    {
        "title": "Binary Search on 2D Matrices",
        "intro": (
            "Matrices with sorted rows or columns allow binary search by linearising indices or walking strategic fronts "
            "that discard rows and columns in bulk."
        ),
        "problems": [
            {
                "title": "Search in 2D Matrix I",
                "file": "Binary Search in 2D Array/Search_in_2D_Matrix_I.cpp",
                "statement": "Treat an m×n matrix with row-major sorted order as a flattened array and decide whether a target exists.",
                "example": "matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3\nOutput: true",
                "explanation": "Because each row starts after the previous ends, the matrix behaves like a single sorted list. Mapping a 1D midpoint back to row and column coordinates lets you reuse classic binary search.",
                "approach": [
                    "Binary search over the range `[0, m*n)` and compute `row = mid / n` and `col = mid % n` at each step.",
                    "Compare the matrix value to the target to decide which half to discard.",
                    "Return true when the target is found; otherwise continue until the window collapses to false.",
                ],
                "time_complexity": "O(log(mn))",
                "space_complexity": "O(1)",
            },
            {
                "title": "Search in 2D Matrix II",
                "file": "Binary Search in 2D Array/Search_in_2D_Matrix_II.cpp",
                "statement": "Given an m×n matrix sorted ascending in every row and column, determine whether a target value exists.",
                "example": "matrix = [[1,4,7,11],[2,5,8,12],[3,6,9,16],[10,13,14,17]], target = 5\nOutput: true",
                "explanation": "Starting from the top-right corner creates a monotonic frontier—moving left decreases values, moving down increases them—so one comparison decides which direction to move.",
                "approach": [
                    "Initialise `i = 0`, `j = m - 1` at the top-right cell.",
                    "If the value exceeds the target, move left; if it is smaller, move down.",
                    "Stop once you either find the target or the indices leave the grid.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Row with Maximum Number of 1s",
                "file": "Binary Search in 2D Array/Row_With_Maximum_Number_of_1.cpp",
                "statement": "In a binary matrix where every row is sorted, return the index of the row containing the most ones.",
                "example": "matrix = [[0,0,1,1],[0,1,1,1],[0,0,0,1]]\nOutput: 1",
                "explanation": "Because each row transitions from 0s to 1s exactly once, a lower-bound search for the first 1 immediately yields the count of ones, allowing a single pass over all rows.",
                "approach": [
                    "Iterate over each row and binary search for the first occurrence of 1 using `lower_bound`.",
                    "Compute the number of ones as `m - first_index`.",
                    "Track the row index with the largest count and return it at the end.",
                ],
                "time_complexity": "O(n log m)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Peak Element in 2D Grid",
                "file": "Binary Search in 2D Array/Peak_Element_II.cpp",
                "statement": "Find a cell `(r, c)` such that its value is strictly greater than the four neighbours above, below, left, and right.",
                "example": "mat = [[10,8,10],[14,13,12],[15,9,11]]\nOutput: [2,0] (one possible peak)",
                "explanation": "Binary searching columns—always moving toward the side containing a larger neighbour—mirrors the 1D peak logic and converges on a local maximum without scanning the whole grid.",
                "approach": [
                    "Pick a middle column and locate the row containing its maximum value.",
                    "Compare that value with the neighbours to the left and right; if a neighbour is larger, move the search range toward it.",
                    "When neither neighbour is larger, the current cell is a peak and its coordinates can be returned.",
                ],
                "time_complexity": "O(n log m)",
                "space_complexity": "O(1)",
            },
        ],
    },
    {
        "title": "Binary Search on Answer Space",
        "intro": (
            "When the feasibility of a solution improves monotonically with respect to a guessed parameter—capacity, distance, "
            "days, or divisor—you can binary search that parameter by simulating the check."
        ),
        "problems": [
            {
                "title": "Aggressive Cows",
                "file": "Binary Search in Answers/Aggressive_Cows.cpp",
                "statement": "Place k cows in stalls positioned along a line so that the minimum distance between any two cows is maximised.",
                "example": "stalls = [1,2,8,4,9], k = 3\nOutput: 3",
                "explanation": "Sorting the stalls makes the minimal distance monotonic: if cows can be spaced by distance d, they can also be spaced by any smaller distance. Binary searching d pinpoints the optimum.",
                "approach": [
                    "Sort stall positions and binary search the candidate distance.",
                    "Greedily place cows from left to right whenever the distance from the last placed cow is at least the guess.",
                    "If all cows fit, move the lower bound up; otherwise shrink the distance.",
                ],
                "time_complexity": "O(n log n + n log L) where L is the coordinate range",
                "space_complexity": "O(1)",
            },
            {
                "title": "Magnetic Force Between Balls",
                "file": "Binary Search in Answers/Magnetic_Force_Between_Balls.cpp",
                "statement": "Choose m baskets along a line to maximise the minimum distance between any two balls.",
                "example": "position = [1,2,3,4,7], m = 3\nOutput: 3",
                "explanation": "After sorting, the feasibility of spacing balls by distance d is monotonic, matching the aggressive cows strategy with an identical greedy check.",
                "approach": [
                    "Sort the basket positions and binary search the answer distance.",
                    "Run a greedy placement check counting how many balls fit for the guessed spacing.",
                    "Adjust the bounds based on whether at least m balls can be placed.",
                ],
                "time_complexity": "O(n log n + n log L)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Minimise Maximum Distance to Gas Station",
                "file": "Binary Search in Answers/Minimise_Maximum_Distance_to_Gas_Station.cpp",
                "statement": "Insert at most k extra gas stations along a highway to minimise the maximum distance between adjacent stations.",
                "example": "stations = [1,2,4,8,9], k = 3\nOutput: 1",
                "explanation": "If we can ensure gaps are at most d, smaller d values are also feasible. Binary searching d while counting how many stations are needed makes the monotonicity explicit.",
                "approach": [
                    "Sort the station positions and binary search the candidate gap size.",
                    "For each adjacent pair, compute how many additional stations are required to keep gaps within the guess.",
                    "If the total exceeds k, increase d; otherwise record the answer and shrink the range.",
                ],
                "time_complexity": "O(n log L)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Capacity to Ship Packages Within D Days",
                "file": "Binary Search in Answers/Capacity_to_Ship_Packages_within_D_days.cpp",
                "statement": "Given package weights, find the minimum ship capacity so that all packages are delivered within D days while maintaining order.",
                "example": "weights = [1,2,3,4,5,6,7,8,9,10], days = 5\nOutput: 15",
                "explanation": "Larger capacities cannot make the schedule worse, creating a monotonic predicate. Binary searching the capacity while simulating the loading process identifies the minimal feasible value.",
                "approach": [
                    "Set bounds between the heaviest package and the sum of all weights.",
                    "Simulate shipping for a guessed capacity, counting how many days it takes.",
                    "If the schedule fits within D days, record the answer and try a smaller capacity; otherwise increase it.",
                ],
                "time_complexity": "O(n log S) where S is the sum of weights",
                "space_complexity": "O(1)",
            },
            {
                "title": "Koko Eating Bananas",
                "file": "Binary Search in Answers/Koko_Eating_Banana.cpp",
                "statement": "Find the minimum integer speed at which Koko must eat bananas to finish all piles within h hours.",
                "example": "piles = [3,6,7,11], h = 8\nOutput: 4",
                "explanation": "If Koko can finish with speed k, any faster speed also works. Binary searching the speed while summing ceil divisions per pile gives the smallest feasible k.",
                "approach": [
                    "Binary search speeds between 1 and the largest pile.",
                    "For each guess, accumulate the hours needed using ceiling division.",
                    "Tighten the bounds depending on whether the total time stays within h.",
                ],
                "time_complexity": "O(n log M) where M is the maximum pile",
                "space_complexity": "O(1)",
            },
            {
                "title": "Minimum Days to Make M Bouquets",
                "file": "Binary Search in Answers/Minimum_Days_to_make_M_Bouquets.cpp",
                "statement": "Determine the minimum day when you can pick m bouquets, each requiring k adjacent blooming flowers.",
                "example": "bloomDay = [1,10,3,10,2], m = 3, k = 1\nOutput: 3",
                "explanation": "The predicate \"can we make m bouquets by day d?\" becomes true once d is large enough. Binary searching d while counting contiguous blooms isolates the minimal day.",
                "approach": [
                    "Check if the total flowers suffice; otherwise return -1 immediately.",
                    "Binary search between day 1 and the maximum bloom day.",
                    "For each guess, sweep the array and count bouquets formed from contiguous flowers with bloom day ≤ guess.",
                ],
                "time_complexity": "O(n log D) where D is the maximum bloom day",
                "space_complexity": "O(1)",
            },
            {
                "title": "Book Allocation Problem",
                "file": "Binary Search in Answers/Book_Allocation_Problem.cpp",
                "statement": "Split an array of book page counts among k students (contiguous assignments) to minimise the maximum pages assigned to a student.",
                "example": "pages = [12,34,67,90], k = 2\nOutput: 113",
                "explanation": "Treat the maximum pages per student as the answer space. If a guess allows a valid partition, any larger number does too, enabling binary search to find the minimum.",
                "approach": [
                    "Bound the answer between the largest single book and the sum of all pages.",
                    "Simulate assigning books sequentially, starting a new student when the running sum exceeds the guess.",
                    "Adjust the search bounds based on whether more than k students are required.",
                ],
                "time_complexity": "O(n log S)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Painter Partition Problem",
                "file": "Binary Search in Answers/Painter_Partition.cpp",
                "statement": "Divide board lengths among k painters (contiguous segments) to minimise the time taken, assuming unit painting speed.",
                "example": "boards = [10,20,30,40], k = 2\nOutput: 60",
                "explanation": "This mirrors book allocation: the minimal makespan is the smallest capacity that allows painting all boards using at most k painters.",
                "approach": [
                    "Binary search the feasible time between the largest board and total length.",
                    "Accumulate board lengths until the guess would be exceeded, then assign a new painter.",
                    "If more than k painters are needed, increase the time; otherwise tighten the upper bound.",
                ],
                "time_complexity": "O(n log S)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Split Array Largest Sum",
                "file": "Binary Search in Answers/Split_Array_Largest_Sum.cpp",
                "statement": "Split an array into k non-empty contiguous subarrays to minimise the largest subarray sum.",
                "example": "nums = [7,2,5,10,8], k = 2\nOutput: 18",
                "explanation": "Exactly the same feasibility function as book allocation applies, with binary search over the maximum allowed subarray sum.",
                "approach": [
                    "Binary search the answer between the max element and total sum.",
                    "For each candidate, greedily form subarrays without exceeding the limit, counting how many are needed.",
                    "If the count exceeds k, raise the limit; otherwise update the answer and reduce it.",
                ],
                "time_complexity": "O(n log S)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Find Nth Root Using Binary Search",
                "file": "Binary Search in Answers/Find_Nth_Root_Using_Binary_Search.cpp",
                "statement": "Given integers n and num, return the integer nth root of num if it exists; otherwise report -1.",
                "example": "num = 64, n = 3\nOutput: 4 (since 4^3 = 64)",
                "explanation": "The function `mid^n` grows monotonically with mid. Binary search evaluates powers while guarding against overflow to locate an exact root when it exists.",
                "approach": [
                    "Binary search between 1 and num inclusive.",
                    "Compute `mid^n` with overflow protection and compare it against num.",
                    "Return mid when the power matches; otherwise adjust the bounds accordingly.",
                ],
                "time_complexity": "O(n log num) assuming O(n) exponentiation",
                "space_complexity": "O(1)",
            },
            {
                "title": "Integer Square Root",
                "file": "Binary Search in Answers/Finding_SQRT_Using_Binary_Search.cpp",
                "statement": "Return the integer floor of the square root of n using binary search.",
                "example": "n = 27\nOutput: 5",
                "explanation": "The squares of integers grow monotonically, so binary search quickly finds the largest integer whose square does not exceed n.",
                "approach": [
                    "Binary search between 0 and n inclusive.",
                    "Compare `mid * mid` with n to decide which half to keep.",
                    "Track the last mid whose square is ≤ n and return it once the search finishes.",
                ],
                "time_complexity": "O(log n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Smallest Divisor Given a Threshold",
                "file": "Binary Search in Answers/Find_the_Smallest_Divisor.cpp",
                "statement": "Find the smallest integer divisor such that the sum of rounded-up divisions of each array element stays within a threshold.",
                "example": "nums = [1,2,5,9], threshold = 6\nOutput: 5",
                "explanation": "As the divisor grows, each ceil division decreases or stays the same, making the total sum a monotonic function suitable for binary search.",
                "approach": [
                    "Binary search divisors between 1 and the maximum array value.",
                    "For each guess, compute the sum of `(num + mid - 1) // mid`.",
                    "If the sum is within the threshold, record the divisor and try smaller ones; otherwise raise it.",
                ],
                "time_complexity": "O(n log M)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Kth Missing Positive Number",
                "file": "Binary Search in Answers/Kth_Missing_Positive_Number.cpp",
                "statement": "Given a strictly increasing positive integer array, return the kth missing positive number.",
                "example": "arr = [2,3,4,7,11], k = 5\nOutput: 9",
                "explanation": "For any candidate value x, the count of missing numbers up to x grows monotonically. Binary search x until that count reaches k, then return the resulting lower bound.",
                "approach": [
                    "Binary search over the value range, such as [1, 2000] in the implementation.",
                    "Use `upper_bound` to count how many array elements are ≤ mid and subtract from mid to get the missing count.",
                    "Tighten the range until `start` lands on the smallest value producing at least k missing numbers.",
                ],
                "time_complexity": "O(log V * log n) where V bounds the search space",
                "space_complexity": "O(1)",
            },
            {
                "title": "Median of Two Sorted Arrays",
                "file": "Binary Search in Answers/Median_of_Two_Sorted_Arrays.cpp",
                "statement": "Compute the median of two sorted arrays in logarithmic time.",
                "example": "nums1 = [1,3], nums2 = [2]\nOutput: 2",
                "explanation": "Binary search on the partition point of the smaller array balances the left and right halves across both arrays so that all elements on the left are ≤ those on the right.",
                "approach": [
                    "Always binary search the shorter array to minimise the range.",
                    "Pick a cut in the first array and derive the matching cut in the second so that the left partition sizes sum to half the total length.",
                    "Adjust the cut until the bordering elements satisfy the ordering constraints, then compute the median from the adjacent values.",
                ],
                "time_complexity": "O(log(min(n, m)))",
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
