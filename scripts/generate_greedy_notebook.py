from __future__ import annotations

import json
from pathlib import Path
import textwrap

ROOT = Path(__file__).resolve().parents[1]
GREEDY_DIR = ROOT / "Greedy"
OUTPUT = GREEDY_DIR / "Greedy_Problems.ipynb"

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
    add_code_from(GREEDY_DIR / problem["file"])


add_markdown(
    """
# Greedy Algorithms Interview Workbook
"""
)
add_markdown(
    """
This notebook curates every greedy-based exercise in the repository. Each section introduces the interview scenario, captures a representative example, outlines why the greedy choice is valid, and embeds the original C++ source so you can revise the implementation side-by-side with the reasoning.
"""
)

categories: list[dict] = [
    {
        "title": "Greedy Building Blocks",
        "intro": "Start with the warm-up problems that reinforce the exchange argument mindset—serving change, matching resources, and keeping decisions locally optimal while maintaining global feasibility.",
        "problems": [
            {
                "title": "Lemonade Change",
                "file": "Lemonade_Change.cpp",
                "statement": "Serve a queue of customers paying with $5, $10, or $20 bills when lemonade costs $5, returning change on the fly or reporting failure if exact change cannot be provided.",
                "example": "bills = [5,5,5,10,20]\nOutput: true",
                "explanation": "Tracking how many $5 and $10 bills you currently own is sufficient. Always prefer giving change with a $10+$5 combination before three $5 bills so that future customers who hand you $10 have a $5 available.",
                "approach": [
                    "Iterate over each bill, incrementing the count for the bill that just arrived.",
                    "When a $10 appears, ensure there is at least one $5 to return; otherwise the sale fails.",
                    "When a $20 appears, prioritise handing back one $10 and one $5; if impossible, fall back to three $5 bills or return false.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Assign Cookies",
                "file": "Assign_Cookies.cpp",
                "statement": "Given children with greed factors and cookies with sizes, distribute cookies so that as many children as possible have a cookie at least as large as their greed factor.",
                "example": "greed = [1,2,3], cookies = [1,1]\nOutput: 1",
                "explanation": "Sorting both lists lets you satisfy the least greedy child first. Each time the current cookie is big enough, assign it and move on; otherwise, discard the small cookie because it cannot help any remaining child.",
                "approach": [
                    "Sort greed factors and cookie sizes in ascending order.",
                    "Walk both arrays with two pointers, advancing the child pointer only when the current cookie suffices.",
                    "Count the number of successful assignments and return it at the end.",
                ],
                "time_complexity": "O(n log n + m log m)",
                "space_complexity": "O(1) extra aside from sorting",
            },
            {
                "title": "Candy Distribution",
                "file": "Candy.cpp",
                "statement": "Distribute candies to children standing in a line such that each child has at least one candy and anyone with a higher rating than an adjacent child receives more candies.",
                "example": "ratings = [1,0,2]\nOutput: 5",
                "explanation": "A left-to-right pass enforces the increasing rule forward, and a right-to-left pass enforces it backward. Taking the maximum candies required by either direction keeps both constraints satisfied with minimal total candies.",
                "approach": [
                    "Initialise everyone with one candy before scanning.",
                    "Sweep from left to right, raising `candies[i]` when `ratings[i] > ratings[i-1]`.",
                    "Sweep from right to left, bumping `candies[i]` to `max(current, right_neighbour + 1)` whenever needed and sum the array.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Valid Parenthesis String with Wildcards",
                "file": "Valid_Parenthesis_String.cpp",
                "statement": "Check whether a string containing '(', ')' and '*' can be interpreted as a valid parenthesis sequence, where '*' may act as '(' or ')' or be ignored.",
                "example": "s = '(*))'\nOutput: true",
                "explanation": "Tracking the feasible range of open brackets (`low`, `high`) after each character keeps all possible substitutions compact. If the upper bound ever drops negative we overuse closings, and at the end the lower bound must reach zero.",
                "approach": [
                    "Maintain two counters: the minimum and maximum possible number of unmatched '(' characters so far.",
                    "Increment both counters on '(', decrement both on ')', and adjust `[low, high]` appropriately when a '*' appears.",
                    "Clamp `low` to zero after each step and ensure `high` never becomes negative; success requires `low == 0` at the end.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
            },
        ],
    },
    {
        "title": "Interval Scheduling and Timeline Management",
        "intro": "These scheduling exercises highlight how sorting by start or finish times unlocks globally optimal schedules for room usage, train platforms, and timeline edits.",
        "problems": [
            {
                "title": "Merge Overlapping Intervals",
                "file": "Merge_Intervals.cpp",
                "statement": "Given a collection of closed intervals, merge all overlapping intervals into the smallest possible set of non-overlapping ranges.",
                "example": "intervals = [[1,3],[2,6],[8,10],[15,18]]\nOutput: [[1,6],[8,10],[15,18]]",
                "explanation": "Sorting by the start time allows you to extend the current window greedily whenever the next interval starts before the existing end. Otherwise, close out the window and begin a new one.",
                "approach": [
                    "Sort intervals lexicographically by their start.",
                    "Track the active merged interval and compare it with the next range.",
                    "If they overlap, extend the end; if not, store the finished range and reset to the new interval.",
                ],
                "time_complexity": "O(n log n)",
                "space_complexity": "O(1) extra (ignoring output)",
            },
            {
                "title": "Insert and Merge an Interval",
                "file": "Insert_Intervals.cpp",
                "statement": "Insert a new interval into an existing list of non-overlapping, sorted intervals and merge overlaps so the output remains sorted and disjoint.",
                "example": "intervals = [[1,3],[6,9]], newInterval = [2,5]\nOutput: [[1,5],[6,9]]",
                "explanation": "Because the original list is sorted, you can copy intervals strictly left of the new range, coalesce anything that overlaps the new interval, then append the remaining right-side intervals.",
                "approach": [
                    "Append all intervals that end before the new interval starts.",
                    "Merge the new interval with any overlapping ranges by expanding its start and end bounds.",
                    "Append the merged interval followed by the untouched right-side intervals.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1) extra (ignoring output)",
            },
            {
                "title": "Erase Overlapping Intervals",
                "file": "Non_Overlapping_Intervals.cpp",
                "statement": "Remove the minimum number of intervals so that the remaining set becomes non-overlapping.",
                "example": "intervals = [[1,2],[2,3],[3,4],[1,3]]\nOutput: 1",
                "explanation": "Sorting by finish time makes it optimal to keep the interval that frees the timeline earliest. Every time a start time conflicts with the previous finish, we count it as a removal.",
                "approach": [
                    "Sort intervals by their end time.",
                    "Scan from earliest finish to latest, counting how many can be kept without overlapping.",
                    "Return total intervals minus the number kept to obtain the removals required.",
                ],
                "time_complexity": "O(n log n)",
                "space_complexity": "O(1) extra",
            },
            {
                "title": "Schedule Maximum Meetings in One Room",
                "file": "N_Meetings_in_One_Room.cpp",
                "statement": "Given start and end times for meetings, select the maximum number that can fit in a single room without overlap.",
                "example": "start = [1,3,0,5,8,5], end = [2,4,6,7,9,9]\nOutput: 4",
                "explanation": "Choosing the meeting that finishes first leaves the most room for future meetings. Sorting by end time and greedily picking compatible meetings yields the optimal count.",
                "approach": [
                    "Zip each meeting's start, end, and original index for sorting.",
                    "Sort the tuple list by increasing end time.",
                    "Iterate through the sorted list, accepting a meeting when its start is not earlier than the time the room becomes free.",
                ],
                "time_complexity": "O(n log n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Minimum Platforms for Trains",
                "file": "Minimum_Number_of_Platform_Required.cpp",
                "statement": "Given arrival and departure times of trains, compute the minimum number of platforms required so no train waits.",
                "example": "arrival = [900, 940, 950, 1100, 1500, 1800]\ndeparture = [910, 1200, 1120, 1130, 1900, 2000]\nOutput: 3",
                "explanation": "Sorting arrivals and departures separately lets you simulate time flowing forward. Each arrival increases the platform requirement until a departure frees one.",
                "approach": [
                    "Sort the arrival and departure arrays individually.",
                    "Use two pointers to walk both arrays, incrementing the count on arrivals and decrementing on departures.",
                    "Track the maximum simultaneous trains observed; that is the number of platforms needed.",
                ],
                "time_complexity": "O(n log n)",
                "space_complexity": "O(1) extra",
            },
        ],
    },
    {
        "title": "Reachability and Range Expansion",
        "intro": "These array problems rely on stretching pointers as far as possible at each step to decide whether a target can be reached or a container can hold more water.",
        "problems": [
            {
                "title": "Container With Most Water",
                "file": "Container_With_Most_Water.cpp",
                "statement": "Pick two vertical lines that, together with the x-axis, form a container holding the most water given the heights array.",
                "example": "heights = [1,8,6,2,5,4,8,3,7]\nOutput: 49",
                "explanation": "The area is limited by the shorter wall, so moving the pointer at the taller wall cannot help. Shifting the shorter wall might find a taller line that increases the area.",
                "approach": [
                    "Initialise two pointers at the ends of the array and compute the area between them.",
                    "Update the maximum area found so far.",
                    "Move the pointer pointing to the shorter line inward, seeking a taller candidate, until the pointers meet.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Jump Game Reachability",
                "file": "Jump_Game.cpp",
                "statement": "Determine whether you can reach the last index of an array when each element denotes the maximum jump length from that position.",
                "example": "nums = [2,3,1,1,4]\nOutput: true",
                "explanation": "Maintaining the furthest index reachable so far is enough. As long as every index up to that reach can be visited, future positions extend or maintain the reach.",
                "approach": [
                    "Track the furthest index reachable, initialised to 0.",
                    "Iterate through the array while the current index does not exceed the reachable bound.",
                    "Update the reachable bound with `max(reach, i + nums[i])` and return true if it eventually covers the last index.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
            },
            {
                "title": "Jump Game II Minimum Jumps",
                "file": "Jump_Game_II.cpp",
                "statement": "Find the minimum number of jumps needed to reach the last index of the array using jumps of lengths up to `nums[i]`.",
                "example": "nums = [2,3,1,1,4]\nOutput: 2",
                "explanation": "Scanning the array in layers—where each layer represents all indices reachable with a fixed number of jumps—lets you decide when to increase the jump count while always expanding to the furthest index possible.",
                "approach": [
                    "Maintain the current layer `[l, r]` that can be reached with the existing number of jumps.",
                    "Within the layer, compute the furthest index reachable by another jump.",
                    "Advance to the next layer `l = r + 1, r = farthest` and increment the jump counter until the last index is inside the window.",
                ],
                "time_complexity": "O(n)",
                "space_complexity": "O(1)",
            },
        ],
    },
    {
        "title": "Job Ordering and Throughput Optimisation",
        "intro": "Greedy heuristics also shine in maximising profit and minimising waiting time by sorting jobs on the most important attribute—deadline or processing time.",
        "problems": [
            {
                "title": "Job Sequencing for Maximum Profit",
                "file": "Job_Sequencing_Problem.cpp",
                "statement": "Given jobs with deadlines and profits, schedule at most one job per timeslot to maximise total profit.",
                "example": "jobs = [[1,2,100],[2,1,19],[3,2,27],[4,1,25],[5,3,15]] (format [id, deadline, profit])\nOutput: [3,142]",
                "explanation": "Sorting jobs by profit descending ensures high-profit tasks are considered first. Each job takes the latest available slot before its deadline, using disjoint-set style scanning to find free times.",
                "approach": [
                    "Sort the job list by profit in descending order.",
                    "Track the maximum deadline to size the schedule array of occupied slots.",
                    "For each job, walk backward from its deadline until an empty slot is found; schedule it there and accumulate profit.",
                ],
                "time_complexity": "O(n log n + n · D) with D bounded by the maximum deadline",
                "space_complexity": "O(D)",
            },
            {
                "title": "Shortest Job First Average Waiting Time",
                "file": "Shortest_Job_First.cpp",
                "statement": "Given execution times of CPU tasks arriving together, compute the average waiting time assuming you always execute the shortest job available next.",
                "example": "executionTime = [4,3,7,1]\nOutput: 4",
                "explanation": "Sorting the processing times ensures the shortest jobs run first, which keeps cumulative waiting time minimal—an application of the rearrangement inequality.",
                "approach": [
                    "Sort all job durations in ascending order.",
                    "Accumulate the running total of time spent so far before each job starts.",
                    "Sum the waiting time contributions and divide by the number of jobs for the average.",
                ],
                "time_complexity": "O(n log n)",
                "space_complexity": "O(1) extra",
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
