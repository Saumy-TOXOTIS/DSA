from __future__ import annotations
import json
from pathlib import Path
import textwrap

ROOT = Path(__file__).resolve().parents[1]
GRAPH_DIR = ROOT / "Graph"
OUTPUT = GRAPH_DIR / "Graph_Problems.ipynb"

cells = []


def to_source_lines(text: str) -> list[str]:
    return [line + "\n" for line in text.splitlines()]


def add_markdown(text: str) -> None:
    text = textwrap.dedent(text).strip("\n")
    cells.append({
        "cell_type": "markdown",
        "metadata": {},
        "source": to_source_lines(text),
    })


def add_code_from(path: Path) -> None:
    source = path.read_text()
    cells.append({
        "cell_type": "code",
        "execution_count": None,
        "metadata": {"language": "cpp"},
        "outputs": [],
        "source": to_source_lines(source),
    })


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
    add_code_from(GRAPH_DIR / problem["file"])


add_markdown("""
# Graph Algorithms Interview Workbook
""")
add_markdown("""
This notebook summarises every graph problem in the repository. Each section introduces the underlying idea, states the interview problem, walks through an illustrative example, outlines the approach, and embeds the original C++ source code so you can study the implementation alongside the theory.
""")

categories: list[dict] = [
    {
        "title": "Graph Foundations and Traversal Patterns",
        "intro": "This section reviews how graphs are represented in code and revisits the two fundamental traversals—breadth-first search (BFS) and depth-first search (DFS).",
        "problems": [
            {
                "title": "Graph Representation Warm-Up",
                "file": "Graph_Introduction.cpp",
                "statement": "Given the number of vertices and edges of an undirected graph, store the graph using both an adjacency matrix and an adjacency list so that later algorithms can reuse those structures.",
                "example": "5 6\n1 2\n1 3\n2 4\n2 5\n3 4\n4 5\nOutput: adjacency matrix and adjacency list populated.",
                "explanation": "The program reads `m` undirected edges and mirrors each connection while populating matrix and list representations, laying the groundwork for whichever traversal strategy is selected later.",
                "approach": [
                    "Read the vertex and edge counts followed by each edge pair.",
                    "Insert every undirected edge twice when building adjacency structures to keep the data symmetric.",
                    "Prefer the adjacency list for sparse graphs and the matrix when constant-time edge lookups are required.",
                ],
                "time_complexity": "O(m)",
                "space_complexity": "O(n^2) for the matrix and O(n + m) for the list",
            },
            {
                "title": "Graph Representation with Templates",
                "file": "Introduction.cpp",
                "statement": "Illustrate graph input handling with reusable templates by simultaneously building adjacency matrices and adjacency lists for an undirected graph.",
                "example": "4 4\n1 2\n2 3\n3 4\n4 1\nOutput: internal adjacency structures filled; no textual output.",
                "explanation": "This snippet mirrors the representation warm-up but emphasises how a shared competitive-programming template wires up graph utilities for future BFS/DFS calls.",
                "approach": [
                    "Leverage helper macros to speed up input of each edge.",
                    "Store matrix entries and list entries in lockstep so both structures stay consistent.",
                    "Leave traversal hooks ready so subsequent functions can execute on the populated containers.",
                ],
                "time_complexity": "O(m)",
                "space_complexity": "O(n^2) for the matrix and O(n + m) for the list",
            },
            {
                "title": "Breadth-First Search Template",
                "file": "BFS.cpp",
                "statement": "Perform a BFS traversal on an undirected graph starting from a given source vertex and print the visitation order.",
                "example": "6 7\n1 2\n1 3\n2 4\n2 5\n3 6\n4 5\n5 6\n1\nOutput: 1 2 3 4 5 6",
                "explanation": "BFS explores the graph layer by layer using a queue. Every time a vertex is popped, all unseen neighbours are queued so that edges crossing to deeper levels are deferred until closer vertices are processed.",
                "approach": [
                    "Push the starting vertex into the queue and mark it visited before exploration begins.",
                    "Iteratively pop from the queue, printing the vertex and pushing unvisited neighbours.",
                    "Maintain a visited array so that each node enters the queue at most once, preventing cycles from looping forever.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Level-Order BFS Traversal",
                "file": "BFS_Breadth_First_Search_Traversal.cpp",
                "statement": "Traverse all vertices reachable from a starting node level by level and output each vertex in the order it leaves the queue.",
                "example": "7\n1\nAdjacency (implicit in code)\nOutput: 1 2 3 4 5 6 7",
                "explanation": "A queue captures the frontier of the current level. When a vertex is popped, all its neighbours are enqueued to form the next layer, giving an ordering that mirrors the layers of the graph rooted at the start node.",
                "approach": [
                    "Mark the start vertex as visited and push it into the queue.",
                    "While the queue is non-empty, pop the front node, print it, and enqueue each unvisited neighbour.",
                    "Reset visitation state between runs when exploring multiple components.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Depth-First Search Template",
                "file": "DFS.cpp",
                "statement": "Run a recursive DFS starting from a requested node in an undirected graph and print the vertices as they are first discovered.",
                "example": "5 4\n1 2\n1 3\n2 4\n3 5\n1\nOutput: 1 2 4 3 5",
                "explanation": "DFS dives along one path until no unvisited neighbours remain, unwinding to explore alternate branches. Because recursion tracks the call stack, the traversal naturally follows the shape of the depth-first tree.",
                "approach": [
                    "Use a recursion helper that marks a vertex as visited and prints it immediately.",
                    "Iterate over each neighbour, recursing only if the neighbour has not been visited yet.",
                    "Support disconnected graphs by invoking DFS for every vertex that remains unvisited after the first call.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Depth-First Search with Explicit Stack",
                "file": "DFS_Depth_First_Search.cpp",
                "statement": "Demonstrate iterative DFS using an explicit stack to list nodes reachable from a source vertex without relying on recursion.",
                "example": "7\n1\nAdjacency (implicit in code)\nOutput: 1 2 4 5 3 6 7",
                "explanation": "Instead of the call stack, an explicit stack holds the frontier. Each pop processes a vertex, and neighbours are pushed so the traversal mimics recursive DFS while offering more control over stack usage.",
                "approach": [
                    "Seed the stack with the starting vertex and mark it visited.",
                    "Pop from the stack, print the node, and push every unvisited neighbour.",
                    "Because a stack is LIFO, pushing neighbours in reverse order can control which branch is explored first.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
        ],
    },
    {
        "title": "Grid Search and Flood-Fill Applications",
        "intro": "Matrix-based problems model each cell as a vertex connected to its neighbours. The following exercises showcase multi-source BFS, flood fill, backtracking, and disjoint-set tricks that are repeatedly asked in interviews.",
        "problems": [
            {
                "title": "Flood Fill",
                "file": "Flood_Fill_Algorithm.cpp",
                "statement": "Given a pixel grid, replace the colour of the region connected to a starting cell with a new colour while leaving the rest of the image unchanged.",
                "example": "4 4\n1 1 1 0\n1 1 0 0\n1 0 1 1\n0 0 1 1\n1 1\n2\nOutput:\n2 2 2 0\n2 2 0 0\n2 0 1 1\n0 0 1 1",
                "explanation": "The starting cell `(1,1)` floods outward to all four-directionally adjacent cells that share the original colour. Every visited pixel is recoloured before exploring its neighbours, ensuring the flood remains bounded by different colours or the grid edge.",
                "approach": [
                    "Capture the original colour, then launch DFS/BFS from the seed cell.",
                    "For each expansion step, test bounds and equality with the starting colour before recursing.",
                    "Overwrite the pixel with the new colour as soon as it is visited so the search never revisits the same location.",
                ],
                "time_complexity": "O(n · m)",
                "space_complexity": "O(n · m) in the worst case because of the recursion stack or queue",
            },
            {
                "title": "Rotting Oranges",
                "file": "Rotten_Oranges.cpp",
                "statement": "Each minute, every rotten orange turns its fresh four-directional neighbours rotten. Compute the minimum time until no fresh orange remains, or report that it is impossible.",
                "example": "3 3\n2 1 1\n1 1 0\n0 1 1\nOutput: Total time to rot : 4",
                "explanation": "Starting with all rotten oranges in the queue captures simultaneous spread. Processing the queue by layers tracks how many minutes have elapsed; if a fresh orange is never reached, the answer would remain incomplete.",
                "approach": [
                    "Push all initially rotten oranges along with time `0` into the queue to run a multi-source BFS.",
                    "Pop the earliest-rotting orange, mark it visited, and infect any fresh neighbour while queuing it with time + 1.",
                    "Track the maximum time stamp seen; if fresh oranges persist at the end, return failure (the sample code prints the elapsed minutes).",
                ],
                "time_complexity": "O(n · m)",
                "space_complexity": "O(n · m)",
            },
            {
                "title": "Capture Surrounded Regions (DFS Version)",
                "file": "Surrounding_Region_Replace_0_with_X.cpp",
                "statement": "Given a board of `'X'` and `'O'`, flip all `'O'` cells that are not connected to the border into `'X'` while preserving the border-connected regions.",
                "example": "4 4\nX X X X\nX O O X\nX X O X\nX O X X\nOutput:\nX X X X\nX X X X\nX X X X\nX O X X",
                "explanation": "Any `'O'` touching the boundary (directly or indirectly) must stay `'O'`. A DFS from every border `'O'` marks the safe cells; every unmarked cell can then be flipped to `'X'`.",
                "approach": [
                    "Scan the outer rows and columns and run DFS from each `'O'` to mark reachable safe cells.",
                    "During DFS, expand in four directions while staying inside the grid and stopping at `'X'`.",
                    "After marking, iterate through the board and flip the unvisited `'O'` cells to `'X'`.",
                ],
                "time_complexity": "O(n · m)",
                "space_complexity": "O(n · m)",
            },
            {
                "title": "Capture Surrounded Regions (BFS Version)",
                "file": "Surrounded_Regions.cpp",
                "statement": "Solve the surrounded-regions problem using breadth-first traversal from the boarder cells to preserve safe `'O'` regions.",
                "example": "4 4\nX X X X\nX O O X\nX X O X\nX O X X\nOutput:\nX X X X\nX X X X\nX X X X\nX O X X",
                "explanation": "The BFS queue starts with every border `'O'`. Popping a cell allows you to enqueue its `'O'` neighbours and mark them in an auxiliary board so that only interior `'O'` cells are flipped at the end.",
                "approach": [
                    "Initialise a queue with all boundary coordinates that contain `'O'` and mark them as safe in a copy board.",
                    "Pop cells, expand to four neighbours, and enqueue any `'O'` that has not been marked yet.",
                    "After BFS completes, iterate through the board: keep safe `'O'` cells and convert the rest to `'X'`.",
                ],
                "time_complexity": "O(n · m)",
                "space_complexity": "O(n · m)",
            },
            {
                "title": "Word Search Backtracking",
                "file": "Word_Search.cpp",
                "statement": "Determine whether a target word can be formed by walking horizontally or vertically adjacent cells in a character grid without reusing a cell.",
                "example": "board = [[A,B,C,E],[S,F,C,S],[A,D,E,E]]\nword = ABCCED\nOutput: true",
                "explanation": "The solver tries each cell that matches the first letter, then explores four directions recursively while marking the path. Backtracking unmarks the cell when a branch fails, allowing other candidates to reuse it.",
                "approach": [
                    "Collect every start position whose letter matches the first character of the word.",
                    "Run DFS with parameters `(row, col, index)` that succeeds when `index == len(word)`.",
                    "Mark a cell as visited while exploring its neighbours and unmark it when returning so alternative paths remain available.",
                ],
                "time_complexity": "O(n · m · 4^L) in the worst case for word length L",
                "space_complexity": "O(L) recursion depth plus the visitation matrix",
            },
            {
                "title": "Distance to Nearest 1",
                "file": "Distance_of_Nearest_Cell_having_1.cpp",
                "statement": "For each cell in a binary matrix, compute the distance to the closest cell containing `1` using four-directional moves.",
                "example": "3 3\n0 0 1\n1 0 0\n0 0 0\nOutput:\n2 1 0\n0 1 1\n1 2 2",
                "explanation": "A multi-source BFS seeded with all `1` cells propagates outward. Each layer extends the distance by one, guaranteeing the first time you reach a cell is the shortest path length.",
                "approach": [
                    "Push every `1` into the queue with distance 0 and set their answers to 0.",
                    "Pop cells, examine four neighbours, and assign `distance + 1` to any unvisited cell before queuing it.",
                    "Continue until the queue empties, at which point every cell holds its closest distance to a `1`.",
                ],
                "time_complexity": "O(n · m)",
                "space_complexity": "O(n · m)",
            },
            {
                "title": "Shortest Path in a Binary Maze",
                "file": "Shortest_Path_in_Binary_Maze.cpp",
                "statement": "Find the length of the shortest path from the top-left to the bottom-right corner of a square grid when you can move in eight directions and must stay on cells containing `0`.",
                "example": "grid = [[0,1],[1,0]]\nOutput: 2",
                "explanation": "A BFS over the eight neighbouring offsets guarantees that the first time the destination cell is popped you have found the minimal number of steps. Obstacles with value `1` prevent expanding into those cells.",
                "approach": [
                    "Reject immediately if either the start or target cell is blocked.",
                    "Push the start cell with distance 1 and repeatedly expand to all eight neighbours that are inside bounds and open.",
                    "Return the distance when the goal cell is reached; if never reached, return `-1`.",
                ],
                "time_complexity": "O(n · m)",
                "space_complexity": "O(n · m)",
            },
            {
                "title": "Minimum Effort Path",
                "file": "Path_With_Minimum_Effort.cpp",
                "statement": "Given a grid of heights, minimise the maximum absolute difference between adjacent cells along a path from the top-left to the bottom-right corner.",
                "example": "heights = [[1,2,2],[3,8,2],[5,3,5]]\nOutput: 2",
                "explanation": "This is Dijkstra's algorithm on a grid: each move costs the effort required to traverse that edge, and the path cost is the maximum edge seen so far. A priority queue always expands the cell with the lowest effort so far, ensuring optimality.",
                "approach": [
                    "Initialise all distances to infinity except the start cell which begins at effort 0.",
                    "Use a min-heap keyed by the current effort, popping the smallest effort cell each iteration.",
                    "For each neighbour, compute the effort as `max(current_effort, height_difference)` and relax if it improves the stored effort.",
                ],
                "time_complexity": "O(n · m · log(n · m))",
                "space_complexity": "O(n · m)",
            },
            {
                "title": "Number of Islands",
                "file": "Number_of_Islands.cpp",
                "statement": "Count how many connected components of land (`1`) exist in a binary grid when connections span in all eight directions.",
                "example": "4 5\n1 1 0 0 0\n1 1 0 0 1\n0 0 0 1 1\n0 0 0 0 0\nOutput: Number of Islands : 3",
                "explanation": "Every time you encounter a land cell that is not yet visited, a DFS marks its entire component—covering horizontal, vertical, and diagonal neighbours—and increments the island count.",
                "approach": [
                    "Iterate over the grid and launch DFS whenever an unvisited land cell is found.",
                    "Within DFS, explore all eight neighbouring positions that remain inside the grid and contain land.",
                    "Maintain a visited matrix to avoid recounting cells and to bound recursion depth.",
                ],
                "time_complexity": "O(n · m)",
                "space_complexity": "O(n · m)",
            },
            {
                "title": "Number of Islands II",
                "file": "Number_of_Islands_II.cpp",
                "statement": "Start with an empty water grid and activate land cells one by one. After each addition, report how many islands exist using an efficient dynamic connectivity structure.",
                "example": "n = 3, m = 3, positions = [[0,0],[0,1],[1,2],[2,1],[1,1]]\nOutput: 1 1 2 3 1",
                "explanation": "The disjoint-set union (DSU) structure links each land cell to its four-directional neighbours when they become land. Merging components decrements the island count, producing an updated total after each operation.",
                "approach": [
                    "Represent each cell as a node `row * m + col` inside a DSU initialised with `n*m` elements.",
                    "When a new land cell arrives, increment the island count and attempt to union it with adjacent land cells, decrementing the count whenever a merge occurs.",
                    "Append the live island count to the answer list after processing each position.",
                ],
                "time_complexity": "O(k α(nm)) (k = number of additions)",
                "space_complexity": "O(n · m)",
            },
            {
                "title": "Number of Distinct Islands",
                "file": "Number_of_Distinct_Islands.cpp",
                "statement": "Count islands by shape, treating translations as identical. Two islands are the same if their relative coordinates match after normalising to a common origin.",
                "example": "grid = [[1,1,0,1],[1,0,0,0],[0,0,0,0],[1,1,0,0]]\nOutput: 2",
                "explanation": "A DFS collects the relative offset of every cell in an island compared with the island's first cell. Storing the vector of offsets in a set ensures that only unique shapes contribute to the answer.",
                "approach": [
                    "Scan the grid and start DFS for every unvisited land cell.",
                    "During DFS, push `(row - base_row, col - base_col)` into a shape vector to normalise each island.",
                    "Insert the shape vector into a set so duplicate shapes collapse into one entry.",
                ],
                "time_complexity": "O(n · m · log S) (S = number of stored shapes)",
                "space_complexity": "O(n · m)",
            },
            {
                "title": "Making a Large Island",
                "file": "Making_a_Large_Island.cpp",
                "statement": "Given a binary grid, flip at most one water cell (`0`) to land (`1`) so the resulting island has the maximum possible area.",
                "example": "grid = [[1,0],[0,1]]\nOutput: 3",
                "explanation": "First unify all existing land components using DSU and record their sizes. For each water cell, gather the unique component identifiers of its neighbours and sum their sizes plus one. The best candidate maximises the island size.",
                "approach": [
                    "Perform a DSU union on every pair of adjacent land cells to build components and track their sizes.",
                    "For each zero cell, collect the unique parent IDs of its land neighbours and compute the potential size if flipped.",
                    "Return the maximum size across all cells, falling back to the size of the existing largest island when no flip helps.",
                ],
                "time_complexity": "O(n · m α(nm))",
                "space_complexity": "O(n · m)",
            },
        ],
    },
    {
        "title": "Word Transformation Graphs",
        "intro": "Changing one letter at a time induces an implicit graph over dictionary words. BFS and DFS help uncover the shortest ladder length and enumerate all minimal ladders.",
        "problems": [
            {
                "title": "Word Ladder I",
                "file": "Word_Ladder_I.cpp",
                "statement": "Return the length of the shortest transformation sequence from a start word to an end word by changing one letter at a time such that each intermediate word exists in the dictionary.",
                "example": "beginWord = hit, endWord = cog, wordList = [hot,dot,dog,lot,log,cog]\nOutput: 5",
                "explanation": "Treat each word as a node and connect words that differ by exactly one letter. A BFS from the starting word discovers the shortest ladder when the end word is popped from the queue.",
                "approach": [
                    "Insert all dictionary words into a set for O(1) lookup and deletion.",
                    "Push the starting word with distance 1, and for each dequeued word, try all letter substitutions at each position.",
                    "When a generated neighbour exists in the set, enqueue it with distance + 1 and erase it to prevent revisits.",
                ],
                "time_complexity": "O(L · 26 · N) (L = word length, N = dictionary size)",
                "space_complexity": "O(N)",
            },
            {
                "title": "Word Ladder II",
                "file": "Word_Ladder_II.cpp",
                "statement": "Enumerate all shortest transformation sequences between two words under the same single-letter substitution rule.",
                "example": "beginWord = hit, endWord = cog, wordList = [hot,dot,dog,lot,log,cog]\nOutput: [[hit,hot,dot,dog,cog],[hit,hot,lot,log,cog]]",
                "explanation": "A BFS computes the minimum distance to each reachable word. Afterwards a DFS backtracks from the target to the source, following only edges that decrease the distance by one, thereby generating all shortest ladders.",
                "approach": [
                    "Run BFS from the start word, storing the minimum number of steps needed to reach each word in a map.",
                    "When the end word is reached, stop expanding deeper levels to keep only shortest paths.",
                    "Use DFS/backtracking from the end word to the start word, appending neighbours whose distance is exactly one less than the current word's distance.",
                ],
                "time_complexity": "O(L · 26 · N + S) (S = total size of returned ladders)",
                "space_complexity": "O(N)",
            },
        ],
    },
    {
        "title": "Disjoint Set Union and Connectivity Planning",
        "intro": "Union–find (disjoint set union, DSU) helps maintain connected components in dynamic graphs. These notes cover template implementations and apply DSU to real interview problems such as provinces, network connectivity, and account merging.",
        "problems": [
            {
                "title": "Disjoint Set Templates",
                "file": "Disjoint_Set.cpp",
                "statement": "Maintain a forest of components that supports joining pairs of nodes and querying whether two vertices share the same ultimate parent.",
                "example": "5 3\n1 2 0\n2 3 0\n4 5 0\nOutput: DSU links {1,2,3} together and {4,5} together (no explicit print).",
                "explanation": "The template exposes `union_by_rank` and `union_by_size` flavours that collapse trees during `find_parent`. It is the backbone for Kruskal, connectivity checks, and other component-based problems.",
                "approach": [
                    "Initialise each vertex so it is its own parent with rank 0 and size 1.",
                    "`find_parent` performs path compression to flatten the tree whenever a node's representative is requested.",
                    "`union_by_rank` attaches the shallower tree under the deeper one, while `union_by_size` attaches the smaller set to the larger.",
                ],
                "time_complexity": "Amortised O(α(n)) per operation",
                "space_complexity": "O(n)",
            },
            {
                "title": "Union by Rank and Size Playground",
                "file": "Disjoint_Set_Union_by_Rank_and_Size.cpp",
                "statement": "Provide a ready-to-use DSU wrapper that exposes both union heuristics for experiments and competitive-programming snippets.",
                "example": "Initialise with n = 6 and union pairs (1,2), (2,3), (4,5). Output: helper prepared for subsequent connectivity queries.",
                "explanation": "This header-style file mirrors the earlier template but is lightweight enough to drop directly into solutions that need just the DSU implementation without extra scaffolding.",
                "approach": [
                    "Expose constructors that size the parent, rank, and size arrays.",
                    "Keep both `union_by_rank` and `union_by_size` so a caller can choose the heuristic that best matches their task.",
                    "Return early whenever both vertices already share the same ultimate parent, which prevents redundant unions.",
                ],
                "time_complexity": "Amortised O(α(n)) per operation",
                "space_complexity": "O(n)",
            },
            {
                "title": "Counting Provinces via DFS",
                "file": "Number_of_Provinces.cpp",
                "statement": "Given an undirected adjacency list, count the number of connected components—also called provinces—using depth-first search.",
                "example": "6 4\n1 2\n2 3\n4 5\n5 6\nOutput: Total Provinces are : 2",
                "explanation": "Each DFS marks every vertex reachable from a starting city. Launching DFS from every unvisited city increments the province tally and ensures every node is explored exactly once.",
                "approach": [
                    "Construct the adjacency list from the undirected edges.",
                    "Iterate through all vertices; when a vertex is unvisited, increment the province counter and start DFS.",
                    "Inside DFS, recursively visit all neighbours to mark the entire component.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Counting Provinces via DSU",
                "file": "Number_of_Provinces_using_Disjoin_set.cpp",
                "statement": "Process an adjacency matrix and use DSU unions to compute how many province-level components remain once all direct connections have been merged.",
                "example": "n = 3 with adjacency matrix\n1 1 0\n1 1 0\n0 0 1\nOutput: 2",
                "explanation": "Whenever the matrix indicates a road between cities `i` and `j`, the DSU unifies them. The number of distinct parents at the end equals the number of provinces.",
                "approach": [
                    "Initialise the DSU with one node per city.",
                    "Iterate over the matrix and union the endpoints whenever a connection appears.",
                    "After processing, count how many vertices are their own parent to derive the province count.",
                ],
                "time_complexity": "O(n^2 α(n))",
                "space_complexity": "O(n^2)",
            },
            {
                "title": "Make Network Connected",
                "file": "Number_of_Operation_to_make_Network_Connected.cpp",
                "statement": "Given `n` computers and existing cables, determine the minimum number of cable reassignments required to make the network fully connected, or state that it is impossible.",
                "example": "n = 4, m = 3 with edges (0,1), (0,2), (1,2)\nOutput: 1",
                "explanation": "Every redundant edge—where both endpoints already share a component—becomes an extra cable. If the number of extra cables is at least the number of components minus one, those cables can connect the components together.",
                "approach": [
                    "Build a DSU and merge endpoints of each cable while counting how many edges were redundant.",
                    "After processing, count the number of connected components by checking distinct parents.",
                    "If extra cables ≥ components − 1, return components − 1; otherwise the task is impossible.",
                ],
                "time_complexity": "O((n + m) α(n))",
                "space_complexity": "O(n)",
            },
            {
                "title": "Minimum Operations to Connect a Graph",
                "file": "Minimum_Number_of_Operation_for_Connecting_Graph.cpp",
                "statement": "Another DSU blueprint that outlines how to count redundant edges and components to compute the minimal rewiring needed to connect an undirected graph.",
                "example": "n = 6, edges = [(0,1),(0,2),(3,4),(2,3),(2,5)]\nOutput: 1",
                "explanation": "The code highlights the two-step logic: count extra edges, count components, and compare. Although the driver is left to the reader, the helper exposes the DSU routines necessary for the standard solution.",
                "approach": [
                    "Track redundant edges while unifying endpoints inside the DSU.",
                    "Compute the number of connected components after processing all edges.",
                    "Return `components - 1` when enough redundant edges exist; otherwise report `-1`.",
                ],
                "time_complexity": "O((n + m) α(n))",
                "space_complexity": "O(n)",
            },
            {
                "title": "Most Stones Removed with Same Row or Column",
                "file": "Most_Stone_Removed.cpp",
                "statement": "Given stones placed on integer grid coordinates, remove as many stones as possible by repeatedly taking a stone that shares a row or column with another stone.",
                "example": "[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]\nOutput: 5",
                "explanation": "Each row and column index becomes a DSU node. Uniting row-node with column-node for every stone forms connected components; the answer is total stones minus the number of connected components that actually contain stones.",
                "approach": [
                    "Map every row to `row` and every column to `column + maxRow + 1` to keep indices unique.",
                    "Union the row node and column node for each stone.",
                    "Count how many DSU parents remain among nodes that appear in the input; subtracting from the stone count yields the maximum removable stones.",
                ],
                "time_complexity": "O(n α(n)) (n = number of stones)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Accounts Merge",
                "file": "Accounts_Merge.cpp",
                "statement": "Merge user accounts when they share at least one email address, returning consolidated name/email lists sorted lexicographically.",
                "example": "[[John,john@mail.com,john_new@mail.com],[John,johnny@mail.com],[John,john@mail.com,johnny@mail.com]]\nOutput: [[John,john@mail.com,john_new@mail.com,johnny@mail.com]]",
                "explanation": "Treat each account as a node. For every email, record the account index that first saw it; subsequent occurrences trigger a DSU union. After processing all emails, gather addresses by their ultimate parent to form merged accounts.",
                "approach": [
                    "Iterate over each account and union the current index with the index that previously owned each email.",
                    "Use a hash map from email to representative index to avoid O(n^2) scanning.",
                    "After unions, bucket emails by DSU parent, sort them, and prefix the original account name.",
                ],
                "time_complexity": "O(m α(n) + m log m) (m = number of emails)",
                "space_complexity": "O(m)",
            },
        ],
    },
    {
        "title": "Cycle Detection and Bipartite Reasoning",
        "intro": "Detecting cycles and classifying graphs as bipartite or safe is foundational for graph correctness. These snippets demonstrate BFS and DFS patterns for both undirected and directed graphs as well as the event-safety concept.",
        "problems": [
            {
                "title": "Bipartite Graph Overview",
                "file": "Bipartite_Graph.cpp",
                "statement": "Outline the criteria for a graph to be bipartite—namely that it can be coloured with two colours so no adjacent vertices share a colour—and prepare grid-based traversal hooks.",
                "example": "n = 3, edges = [(1,2),(2,3)]\nOutput: true",
                "explanation": "Although the helper body is left empty, the file documents the definition and sets up adjacency structures for applying either BFS or DFS colouring in companion files.",
                "approach": [
                    "Represent the graph via adjacency matrix/list for convenient traversal.",
                    "Attempt to colour each connected component with two colours while ensuring neighbouring vertices differ.",
                    "Report failure if you encounter an odd-length cycle during colouring.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Bipartite Check via BFS",
                "file": "Bipartite_Graph_BFS.cpp",
                "statement": "Colour an undirected graph level by level using BFS and verify that no adjacent nodes share the same colour.",
                "example": "4 4\n1 2\n2 3\n3 4\n4 1\nOutput: Graph is bipartite",
                "explanation": "Starting from an arbitrary source, BFS alternates colours for each layer. Encountering an edge that connects two vertices with the same colour implies the graph contains an odd cycle and is not bipartite.",
                "approach": [
                    "Initialise all vertex colours to `-1` (uncoloured).",
                    "Perform BFS from each uncoloured vertex, assigning alternating colours as neighbours are discovered.",
                    "If a neighbour already has the same colour as the current node, mark the graph as non-bipartite.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Bipartite Check via DFS",
                "file": "Bipartite_Graph_DFS.cpp",
                "statement": "Use recursive DFS to colour neighbouring nodes with opposite colours and detect conflicts that indicate non-bipartiteness.",
                "example": "3 3\n1 2\n2 3\n1 3\nOutput: Graph is not bipartite",
                "explanation": "DFS walks down each branch, flipping the colour for every recursive call. If recursion returns to a node with the same colour as its parent, an odd cycle exists.",
                "approach": [
                    "Start DFS at every uncoloured node with an initial colour (say 0).",
                    "On exploring a neighbour, assign the opposite colour and continue recursively.",
                    "Abort and flag failure when a neighbour already bears the current colour.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Cycle Detection in Undirected Graph (BFS)",
                "file": "Cycle_Detection_BFS.cpp",
                "statement": "Detect cycles in an undirected graph by performing BFS while tracking each node's parent.",
                "example": "5 5\n1 2\n2 3\n3 4\n4 2\n4 5\nOutput: Cycle exists",
                "explanation": "A cycle is confirmed when BFS encounters a neighbour that has been visited already and is not the current node's parent. The queue stores `(node, parent)` pairs to facilitate this check.",
                "approach": [
                    "Push `(start, -1)` for every unvisited vertex and mark it as visited on pop.",
                    "For each neighbour, either enqueue it if unseen or report a cycle if it is not the parent.",
                    "Repeat until all components have been explored.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Cycle Detection in Undirected Graph (DFS)",
                "file": "Cycle_Detection_DFS.cpp",
                "statement": "Detect cycles using recursive DFS with parent tracking in an undirected graph.",
                "example": "4 4\n1 2\n2 3\n3 4\n4 2\nOutput: Cycle exists",
                "explanation": "DFS marks each vertex as visited and recurses into neighbours. Discovering a visited neighbour that is not the parent indicates an odd back-edge and hence a cycle.",
                "approach": [
                    "For every unvisited vertex, run DFS with the parent initialised to `-1`.",
                    "Mark the node visited, then explore each neighbour recursively.",
                    "If a neighbour is visited and not the parent, short-circuit and report a cycle.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Explicit DFS Cycle Check",
                "file": "Cycle_Detection_in_Undirected_Graph_DFS.cpp",
                "statement": "Provide a standalone DFS implementation for cycle detection that demonstrates the visited/parent pattern on a sample graph.",
                "example": "Graph edges hardcoded inside the file\nOutput: YES",
                "explanation": "The routine performs DFS from every node, returning true once a cycle is detected. Its hardcoded adjacency setup doubles as a reference for building test cases quickly.",
                "approach": [
                    "Store the example graph adjacency list in code.",
                    "Invoke DFS on each component, checking neighbours for already-visited vertices other than the parent.",
                    "Print an affirmative result when a cycle appears; otherwise report `NO`.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Cycle Detection in Directed Graph (Kahn's Algorithm)",
                "file": "Cycle_Detection_in_Directed_Graph_BFS.cpp",
                "statement": "Use Kahn's algorithm to determine whether a directed graph contains a cycle by inspecting the size of the produced topological order.",
                "example": "4 4\n1 2\n2 3\n3 4\n4 2\nOutput: Cycle Detected!",
                "explanation": "Kahn's algorithm removes vertices with indegree zero. If any vertices remain unprocessed at the end, they must be part of a directed cycle because they never reached indegree zero.",
                "approach": [
                    "Compute indegrees and push all zero-indegree vertices into the queue.",
                    "Process vertices, decrementing the indegree of their neighbours and pushing new zero-indegree vertices.",
                    "Compare the number of processed vertices with `n`; fewer vertices imply a cycle.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Cycle Detection in Directed Graph (DFS)",
                "file": "Cycle_Detection_in_Directed_Graph_DFS.cpp",
                "statement": "Detect directed cycles via DFS by tracking the recursion stack to find back edges.",
                "example": "4 4\n1 2\n2 3\n3 1\n3 4\nOutput: Cycle exists",
                "explanation": "A recursion stack array records whether a node is part of the current DFS path. Encountering a neighbour that is on the stack signals a cycle.",
                "approach": [
                    "For each unvisited node, run DFS and mark it on the recursion stack before exploring children.",
                    "If a neighbour is unvisited, recurse; if it is already on the stack, immediately return true.",
                    "On return, remove the node from the recursion stack to backtrack correctly.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Eventual Safe States (DFS)",
                "file": "Eventual_Safe_State.cpp",
                "statement": "Identify all nodes in a directed graph that do not eventually reach a cycle using DFS and recursion-stack tracking.",
                "example": "Graph edges hardcoded inside the file with `n = 10`\nOutput: number of safe nodes",
                "explanation": "Nodes that enter a cycle—or reach another node that is part of a cycle—are unsafe. The DFS marks nodes in the recursion stack; if a back edge occurs, the current chain is unsafe. Nodes that finish without encountering a cycle are marked safe.",
                "approach": [
                    "Maintain arrays for visited nodes, recursion path, and safety status.",
                    "During DFS, mark nodes on the path; encountering a back edge returns true to signal a cycle.",
                    "After exploring all outgoing edges, clear the path mark and label the node safe.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Eventual Safe States (Topological Order)",
                "file": "Eventual_Safe_State_BFS.cpp",
                "statement": "Reverse the edges and perform Kahn's algorithm to collect all nodes that can reach a terminal node without touching a cycle.",
                "example": "Directed graph with edges reversed during processing\nOutput: safe vertices listed",
                "explanation": "In the reversed graph, safe nodes are those that eventually reach a terminal node. Nodes whose indegree drops to zero in the reversed view are safe and can be output in sorted order.",
                "approach": [
                    "Build the reverse graph and compute indegrees of reversed edges.",
                    "Queue nodes with zero indegree and perform BFS, collecting each popped vertex as safe.",
                    "Sort or output the safe nodes once the queue empties.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Eventual Safe States (Template DFS)",
                "file": "Eventual_Safe_State_DFS.cpp",
                "statement": "Provide a reusable DFS lambda that classifies nodes as safe or unsafe based on cycle detection in directed graphs.",
                "example": "Input: adjacency list built from `m` edges; Output: list of safe nodes",
                "explanation": "This version reads a graph and uses a recursive lambda to mark nodes in the recursion stack. After DFS completes, nodes with `check[i] == 1` are safe.",
                "approach": [
                    "Construct the adjacency list from input edges.",
                    "Run the DFS lambda on every unvisited node, toggling the `path` and `check` arrays accordingly.",
                    "After the traversal, iterate through `check` to identify and print safe nodes.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
        ],
    },
    {
        "title": "Topological Ordering and DAG Techniques",
        "intro": "Directed acyclic graphs (DAGs) unlock linear ordering of tasks, alien alphabets, and efficient shortest paths. The problems below cover both DFS and BFS-based topological sorts and apply them to real scenarios.",
        "problems": [
            {
                "title": "DFS-Based Topological Sort",
                "file": "Topological_Sorting_DFS.cpp",
                "statement": "Produce a topological ordering of a DAG using depth-first search and a stack to record finishing times.",
                "example": "6 6\n5 0\n5 2\n4 0\n4 1\n2 3\n3 1\nOutput: 5 4 2 3 1 0",
                "explanation": "DFS visits nodes and pushes them onto a stack after exploring all descendants. Popping the stack yields a valid topological order where every edge points from earlier to later nodes.",
                "approach": [
                    "Construct the adjacency list for the directed graph.",
                    "Invoke DFS on each unvisited node, pushing the node onto a stack after exploring its neighbours.",
                    "Pop the stack at the end to obtain the topological ordering.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Kahn's Algorithm for Topological Sort",
                "file": "Kahn_Algorithm_BFS_Topological_Sorting.cpp",
                "statement": "Generate a topological order by repeatedly removing vertices with zero indegree and pushing them into a queue.",
                "example": "Graph hardcoded in file with eight vertices\nOutput: topological order such as 8 1 2 3 7 4 5 6",
                "explanation": "Kahn's algorithm treats indegree-zero vertices as ready tasks. Removing them and decrementing indegrees of neighbours mirrors scheduling constraints and ensures no edge points backward in the final order.",
                "approach": [
                    "Compute the indegree of every vertex from the adjacency list.",
                    "Push all zero-indegree vertices into a queue and repeatedly pop/append them to the answer list.",
                    "When removing a vertex, decrement neighbour indegrees and enqueue any that fall to zero.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Topological Sort Utility (Macro Version)",
                "file": "Topological_Sort_KAHN_Algorithm.cpp",
                "statement": "A macro-heavy competitive-programming version of Kahn's algorithm ready to paste into solutions that need a quick topological ordering.",
                "example": "Graph edges defined in code produce an ordering printed to stdout.",
                "explanation": "This version emphasises template macros but follows the same indegree/queue logic. Keeping both versions in the repository helps illustrate how to adapt the technique to different coding styles.",
                "approach": [
                    "Precompute indegrees by iterating over adjacency lists.",
                    "Push all zero-indegree vertices and perform BFS to build the ordering vector.",
                    "Print the resulting sequence once the queue empties.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Recursive Topological Search",
                "file": "Topological_Search.cpp",
                "statement": "Showcase a DFS-based topological sort that stores vertices in a stack ordered by completion time before printing the sequence.",
                "example": "Example graph encoded inside the file\nOutput: order such as 8 1 2 3 7 4 5 6",
                "explanation": "This utility mirrors the classical DFS approach but prints the order while popping from the stack, making it easy to adapt for problems that only need the ordering output.",
                "approach": [
                    "Seed the DFS from each unvisited node.",
                    "After visiting all children, push the current node onto the stack.",
                    "Once DFS finishes, pop nodes from the stack and print them in sequence.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Alien Dictionary",
                "file": "Alien_Dictionary.cpp",
                "statement": "Given `n` lexicographically sorted words in an alien language that uses the first `k` Latin letters, infer a valid ordering of those letters.",
                "example": "n = 5, k = 4, words = [baa, abcd, abca, cab, cad]\nOutput: b d a c",
                "explanation": "Comparing adjacent words reveals the first differing characters, which imply ordering constraints. Building a graph of these relations and performing topological sort yields a valid alphabet order.",
                "approach": [
                    "Map each letter to an index and compare neighbouring words to extract precedence edges.",
                    "Run DFS-based topological sort over the letter graph.",
                    "Pop nodes from the stack and convert them back into characters to print the alien ordering.",
                ],
                "time_complexity": "O(L + k) (L = total length of words)",
                "space_complexity": "O(k)",
            },
            {
                "title": "Course Schedule I & II",
                "file": "Course_Schedule_I_and_II.cpp",
                "statement": "Determine whether it is possible to finish all courses given prerequisite pairs and, if so, produce a valid course order.",
                "example": "n = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]\nOutput: Course Scheduling Possible!\n0 1 2 3",
                "explanation": "Kahn's algorithm identifies whether the graph is acyclic. If all vertices are processed, the queue order forms a valid schedule; otherwise a cycle prevents completion.",
                "approach": [
                    "Treat each prerequisite pair as a directed edge from prerequisite to course.",
                    "Compute indegrees, queue zero-indegree courses, and process them in BFS order.",
                    "If all courses appear in the resulting list, return it; otherwise report impossibility.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Shortest Paths in DAG (Stack Method)",
                "file": "Shorted_Path_in_Directed_Acyclic_Graph.cpp",
                "statement": "Compute single-source shortest paths in a DAG by first generating a topological order via DFS and then relaxing edges in that order.",
                "example": "Graph with edges encoded in the file\nOutput: array of shortest distances from the source",
                "explanation": "Once nodes are ordered topologically, relaxing edges from left to right ensures every predecessor is processed before its successors, delivering linear-time shortest paths.",
                "approach": [
                    "Perform DFS to populate a stack with nodes in reverse topological order.",
                    "Initialise distances with infinity except for the source node set to zero.",
                    "Pop nodes from the stack and relax outgoing edges, updating distances when shorter paths are found.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Shortest Paths in DAG (Kahn Variant)",
                "file": "Shortest_Path_DAG.cpp",
                "statement": "Use a Kahn-style queue to compute shortest paths in a DAG while dynamically relaxing edges once their indegree drops to zero.",
                "example": "Input graph read from stdin with weights; output distance array",
                "explanation": "Processing vertices when all prerequisites are done mimics topological order. Each time a node is dequeued, the algorithm tries to relax its outgoing edges, yielding shortest distances in a single pass.",
                "approach": [
                    "Read the weighted DAG and compute indegrees for each vertex.",
                    "Initialise distances, queue zero-indegree nodes, and propagate relaxations while decrementing indegrees.",
                    "After traversal, print the distance array which contains `INF` for unreachable nodes.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
        ],
    },
    {
        "title": "Shortest Path Algorithms",
        "intro": "From BFS on unit-weight graphs to Dijkstra, Bellman–Ford, and Floyd–Warshall, these implementations highlight the trade-offs between performance and flexibility for weighted graphs.",
        "problems": [
            {
                "title": "Shortest Path in Undirected Graph (Unit Weight)",
                "file": "Shortest_Path_Undirected_Graph_Unit_Weight.cpp",
                "statement": "Compute shortest distances from a source in an undirected graph where every edge has weight one.",
                "example": "8 7\n0 1\n0 3\n1 2\n3 4\n4 5\n5 6\n6 7\nSource: 0\nOutput: 0 1 2 1 2 3 3 4",
                "explanation": "A standard BFS suffices when all edges have the same weight. The queue maintains pairs `(node, distance)`, and distances are updated only when a shorter path is discovered.",
                "approach": [
                    "Initialise all distances to infinity except the source which is zero.",
                    "Push the source into the queue and expand neighbours, updating distance if `dist[cur] + 1` improves the stored value.",
                    "Continue BFS until the queue is empty, printing the distance array.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Shortest Path in Undirected Graph (Weighted)",
                "file": "Shortest_Path_in_Undirected_Graph.cpp",
                "statement": "Find the minimum number of edges required to reach every vertex in a small undirected example graph with unit weights.",
                "example": "Graph hardcoded inside the file with nine vertices\nOutput: distance array from the chosen source",
                "explanation": "Although the sample graph is embedded in the file, it illustrates how BFS discovers shortest paths in terms of edge count, pushing neighbours only when a shorter distance is found.",
                "approach": [
                    "Fill the adjacency list, set all distances to a large value, and enqueue the source with distance zero.",
                    "When dequeuing a vertex, inspect each neighbour and relax `dist[neigh]` to `dist[cur] + 1` if it is smaller.",
                    "Print the distance array after BFS completes.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Dijkstra's Algorithm",
                "file": "Dijkstra_Algorithm.cpp",
                "statement": "Compute shortest paths in a non-negative weighted graph using both priority-queue and set-based implementations of Dijkstra's algorithm.",
                "example": "n = 5, m = 7 with weighted edges read from stdin\nOutput: shortest path and distance from source to destination",
                "explanation": "The implementation stores both a priority queue and an ordered set version to demonstrate different ways to pick the minimum-distance vertex. Parents are tracked to reconstruct the path.",
                "approach": [
                    "Initialise all distances to infinity and set the source distance to zero.",
                    "Repeatedly extract the node with the smallest tentative distance and relax its outgoing edges.",
                    "Maintain a parent array so the shortest path can be printed after the algorithm terminates.",
                ],
                "time_complexity": "O(m log n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Bellman–Ford Algorithm",
                "file": "Bellman_Ford_Algorithm.cpp",
                "statement": "Handle graphs with negative edge weights by repeatedly relaxing all edges and checking for negative cycles.",
                "example": "n = 5, m = 8 (edges read from stdin), source = 0, destination = 4\nOutput: shortest distance or 'Negative Cycle Detected!'",
                "explanation": "Bellman–Ford relaxes every edge `n-1` times so that the shortest paths propagate even with negative weights. A final pass detects whether any edge can still be relaxed, signalling a negative cycle.",
                "approach": [
                    "Store all edges in a list to iterate easily during each relaxation round.",
                    "Run `n-1` iterations updating distances whenever `dist[u] + w < dist[v]`.",
                    "Perform one more iteration; if any edge relaxes, report a negative cycle instead of a distance.",
                ],
                "time_complexity": "O(n · m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Floyd–Warshall Algorithm",
                "file": "Floyd_Warshall_Algorithm.cpp",
                "statement": "Compute all-pairs shortest paths and detect negative cycles by repeatedly trying intermediate vertices.",
                "example": "n = 4 with weighted adjacency matrix input\nOutput: distance matrix and negative-cycle warning if applicable",
                "explanation": "Floyd–Warshall tests whether going from `i` to `j` via `k` is shorter than the current best path. After `n` iterations, `graph[i][j]` holds the shortest distance if the graph has no negative cycle.",
                "approach": [
                    "Initialise the distance matrix with direct edge weights (or infinity when no edge exists).",
                    "Iterate `k` from 1 to `n`, relaxing every pair `(i,j)` using `k` as an intermediate vertex.",
                    "Check the diagonal for negative values afterwards to detect negative cycles.",
                ],
                "time_complexity": "O(n^3)",
                "space_complexity": "O(n^2)",
            },
            {
                "title": "Cheapest Flight Within K Stops",
                "file": "Cheapest_Flight_Within_K_Stops.cpp",
                "statement": "Find the minimum price to travel from `src` to `dst` using at most `k` stops in a directed flight network.",
                "example": "n = 4, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1\nOutput: 200",
                "explanation": "A BFS-style queue tracks `(stops, node, cost)` tuples. The algorithm explores neighbours as long as the stop count does not exceed `k`, updating the best price seen for each node.",
                "approach": [
                    "Build adjacency lists with edge costs and initialise all distances to infinity.",
                    "Push `(0, src, 0)` and expand nodes layer by layer while the number of stops ≤ `k`.",
                    "Relax costs for neighbours and push updated tuples when a cheaper price is found.",
                ],
                "time_complexity": "O(k · m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "City with Minimum Reachable Neighbours",
                "file": "City_With_the_Smallest_Number_of_Neighbors_at_a_Threshold_Distance.cpp",
                "statement": "Using repeated Floyd–Warshall relaxations, find the city with the fewest neighbours reachable within a distance threshold (breaking ties by the largest index).",
                "example": "n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], threshold = 4\nOutput: 3",
                "explanation": "The algorithm first computes all-pairs shortest paths. It then counts, for each city, how many others are reachable within the threshold and picks the city with the smallest count (preferring higher indices on ties).",
                "approach": [
                    "Initialise the distance matrix and run Floyd–Warshall to compute all-pairs distances.",
                    "For each city, count how many distances are ≤ threshold.",
                    "Track the city with the smallest count, updating the answer whenever a tie occurs with a larger city index.",
                ],
                "time_complexity": "O(n^3)",
                "space_complexity": "O(n^2)",
            },
            {
                "title": "Minimum Multiplications to Reach Target",
                "file": "Minimum_Multiplication_To_Reach_End.cpp",
                "statement": "Starting from a value `start`, multiply by any number in the array modulo `100000` to reach `end` with the minimum number of multiplications.",
                "example": "n = 3, start = 3, end = 30, arr = [2,5,7]\nOutput: 2",
                "explanation": "The numbers modulo `100000` form a graph where each multiplication leads to a neighbour. BFS over this implicit graph finds the minimum number of steps to reach the target value.",
                "approach": [
                    "Treat each value from 0 to 99999 as a vertex and push the start value with distance zero.",
                    "Pop values from the queue and explore neighbours by multiplying with each array value modulo 100000.",
                    "Stop when the destination value is dequeued; otherwise return the stored distance.",
                ],
                "time_complexity": "O(100000 · n) in the worst case",
                "space_complexity": "O(100000)",
            },
            {
                "title": "Number of Ways to Arrive at Destination",
                "file": "Number_of_Ways_to_Arrive_Destination.cpp",
                "statement": "Count how many shortest paths exist from vertex `0` to vertex `n-1` in a weighted undirected graph, modulo 1e9+7.",
                "example": "n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]\nOutput: 4",
                "explanation": "The algorithm runs Dijkstra's shortest path while counting how many minimal-cost ways reach each vertex. When a node is relaxed with a smaller cost, its path count resets; when another path ties the best cost, the counts are accumulated.",
                "approach": [
                    "Build adjacency lists with weights and seed Dijkstra with the source node.",
                    "When relaxing an edge, update both the distance and the number of ways modulo 1e9+7.",
                    "At the end, return the count stored for the destination vertex.",
                ],
                "time_complexity": "O(m log n)",
                "space_complexity": "O(n)",
            },
        ],
    },
    {
        "title": "Minimum Spanning Trees and Critical Connections",
        "intro": "These patterns rely on DFS timestamps and DSU to identify critical vertices/edges and to build minimum spanning trees for weighted graphs.",
        "problems": [
            {
                "title": "Tarjan's Articulation Points",
                "file": "Articulation_Points.cpp",
                "statement": "Find all articulation points in an undirected graph—vertices whose removal increases the number of connected components.",
                "example": "n = 5, m = 5 with edges (1,2),(1,3),(3,4),(3,5),(4,5)\nOutput: articulation vertices such as {1,3}",
                "explanation": "Using DFS timestamps and low-link values, the algorithm checks whether any child subtree can reach an ancestor of the current node. Root vertices are articulation points when they have more than one child.",
                "approach": [
                    "Perform DFS, storing discovery time (`time_insertion`) and the lowest reachable time (`lowest_time`) for each vertex.",
                    "Skip the parent edge to avoid trivial cycles.",
                    "Mark a node as an articulation point if a child cannot reach an ancestor (i.e., `lowest_time[child] >= time_insertion[node]`) or if the root has more than one child.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Tarjan's Bridges",
                "file": "Bridges_in_Graph_Tarjan_Algorithm.cpp",
                "statement": "Identify all bridges—edges whose removal disconnects the graph—using Tarjan's DFS algorithm.",
                "example": "n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]\nOutput: [[1,3]]",
                "explanation": "The DFS records discovery times and low values. If the low value of a child exceeds the discovery time of the current node, the edge leading to that child is a bridge because the subtree cannot reach an earlier vertex without it.",
                "approach": [
                    "Build adjacency lists from the connections and start DFS at node 0.",
                    "On visiting a neighbour, recurse if unvisited; otherwise update the low-link value with the neighbour's discovery time.",
                    "After returning from recursion, append the edge `(node, child)` to the bridge list when `low[child] > tin[node]`.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Kosaraju's Strongly Connected Components",
                "file": "Strongly_Connected_Components_Kosaraju_Algorithm.cpp",
                "statement": "Decompose a directed graph into strongly connected components (SCCs) using Kosaraju's two-pass DFS technique.",
                "example": "n = 5, m = 6 with edges (1,2),(2,3),(3,1),(3,4),(4,5),(5,4)\nOutput: SCC count = 2",
                "explanation": "Kosaraju performs a DFS to record vertices by finishing time, reverses all edges, and performs DFS in stack order on the reversed graph. Each DFS tree in the second pass represents an SCC.",
                "approach": [
                    "Run DFS on the original graph, pushing nodes onto a stack once their recursion unwinds.",
                    "Reverse every edge and reset visitation state.",
                    "Pop vertices from the stack and DFS on the reversed graph; each traversal counts as a new strongly connected component.",
                ],
                "time_complexity": "O(n + m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Prim's Algorithm (Detailed)",
                "file": "Minimum_Spanning_Tree.cpp",
                "statement": "Implement Prim's algorithm with a priority queue to build a minimum spanning tree (MST) of a weighted undirected graph.",
                "example": "n = 6 with weighted edges (hardcoded)\nOutput: MST edges and total weight",
                "explanation": "Starting from an arbitrary vertex, Prim's algorithm repeatedly adds the smallest-weight edge that connects the growing MST to a new vertex. A min-heap keeps track of candidate edges.",
                "approach": [
                    "Push `(0, start, -1)` into the priority queue and pop the minimum edge each iteration.",
                    "Skip edges leading to already-visited nodes; otherwise add the edge to the MST and accumulate its weight.",
                    "For each newly visited node, push all outgoing edges that connect to unvisited nodes.",
                ],
                "time_complexity": "O(m log n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Prim's Algorithm (Compact)",
                "file": "MST_Prims_Algorithm.cpp",
                "statement": "A streamlined Prim's implementation that stores the MST edges as `(parent, node, weight)` tuples.",
                "example": "Input: graph from stdin, Output: list of MST edges and the summed weight",
                "explanation": "This variant emphasises clarity: it stores the parent alongside each node when pushing into the priority queue so the MST edges can be reconstructed directly.",
                "approach": [
                    "Read all edges and build adjacency lists.",
                    "Push `(weight, node, parent)` triples into a min-heap and pop them until all nodes are visited.",
                    "Record edges as they are added and accumulate the total MST weight.",
                ],
                "time_complexity": "O(m log n)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Kruskal's Algorithm (Skeleton)",
                "file": "Kruskal_Algorithm.cpp",
                "statement": "Explain the steps of Kruskal's algorithm using DSU unions and read edges sorted by weight to build an MST.",
                "example": "n = 5, edges listed in ascending order by weight\nOutput: total MST weight",
                "explanation": "Kruskal sorts edges by weight and repeatedly adds the lightest edge that connects two different components. The DSU prevents cycles by rejecting edges whose endpoints already share a parent.",
                "approach": [
                    "Sort edges by weight before processing.",
                    "For each edge, check whether its endpoints have the same DSU parent; if not, union them and add the weight to the MST sum.",
                    "Repeat until `n-1` edges have been added or all edges are processed.",
                ],
                "time_complexity": "O(m log m)",
                "space_complexity": "O(n)",
            },
            {
                "title": "Kruskal's Algorithm (Complete)",
                "file": "Kruskal_Algorithm_MST.cpp",
                "statement": "A full Kruskal implementation that sorts edges, unions components, and prints the MST weight plus the chosen edges.",
                "example": "Input edges read from stdin; Output: MST weight",
                "explanation": "This implementation builds on the DSU class to manage component merges and stores selected edges in a vector so the resulting MST can be inspected or printed.",
                "approach": [
                    "Read all weighted edges and push them into a vector sorted by weight.",
                    "Process edges in ascending order, unioning endpoints when they belong to different sets.",
                    "Accumulate weight and append edges to the MST list for later use or debugging.",
                ],
                "time_complexity": "O(m log m)",
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
