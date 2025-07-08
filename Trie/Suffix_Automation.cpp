//  ████████╗_██████╗_██╗__██╗_██████╗_████████╗██╗███████╗
//  ╚══██╔══╝██╔═══██╗╚██╗██╔╝██╔═══██╗╚══██╔══╝██║██╔════╝
//  ___██║___██║___██║_╚███╔╝_██║___██║___██║___██║███████╗
//  ___██║___██║___██║_██╔██╗_██║___██║___██║___██║╚════██║
//  ___██║___╚██████╔╝██╔╝_██╗╚██████╔╝___██║___██║███████║
//  ___╚═╝____╚═════╝_╚═╝__╚═╝_╚═════╝____╚═╝___╚═╝╚══════╝
//  _______________________________________________________

/*##### Submission By - Saumy Tiwari #####*/

/*################ Macros ################*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define TOXOTIS int main()
ll I, i, j, k;
#define lMAX LLONG_MAX
#define lMIN LLONG_MIN
#define elif else if
#define v(T) vector<T>
#define P(T1,T2) pair<T1,T2>
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define psb push_back
#define __lcm(a,b) (a*b)/(__gcd(a,b))
#define MOD 1000000007ll
#define f1(I,a,t,b) for((I) = (a);(I) < (t);(I)+=(b))
#define f2(I,a,t,b) for((I) = (a);(I) >= (t);(I)-=(b))
#define d_ll(n) ll n;cin>>n;
#define d_string(s) string s;cin>>s;
#define d_float(n) float n;cin>>n;
#define d_double(n) double n;cin>>n;
#define d_llArr(a,n) ll a[n];f1(i,0,n,1){cin>>a[i];}
#define d_llMat(a,row,column) ll a[row][column];f1(i,0,row,1){f1(j,0,column,1){cin>>a[i][j];}}
#define d_llVecArr(a,n) v(ll) a;f1(i,0,n,1){ll VAR;cin>>VAR;a.push_back(VAR);}
#define d_floatArr(a,n) float a[n];f1(i,0,n,1){cin>>a[i];}
#define d_doubleArr(a,n) double a[n];f1(i,0,n,1){cin>>a[i];}
#define Fast_IO ios_base::sync_with_stdio(0);cin.tie(0);//fast input and output
ll expo(ll a,ll b,ll mod){ll result=1;while(b>0){if(b&1)result=(result*a)%mod;a=(a*a)%mod;b=b>>1;}return result;}
ll mminvprime(ll a,ll b){return expo(a,b-2,b);}
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return(((a+b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return(((a*b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return((a-b+m)%m);}
ll mod_div(ll a,ll b,ll m){a=a%m;b=b%m;return(mod_mul(a,mminvprime(b,m),m)+m)%m;}

/*########### Extra Functions ###########*/

//Find LCS (Longest Common Substring) between two string s and t

//Suffix Automation
/**
 * @class SuffixAutomaton
 * @brief A class to build and represent a Suffix Automaton for a given string.
 *
 * This structure is a minimal DFA (Deterministic Finite Automaton) that accepts
 * all substrings of a string. It is built in O(N) time and space, where N is
 * the length of the string.
 */
class SuffixAutomaton {
private:
    /**
     * @struct State
     * @brief Represents a single state (or node) in the Suffix Automaton.
     */
    struct State {
        ll len;      // The length of the longest substring ending at this state.
        ll link;     // The suffix link to another state.
        
        // Transitions to next states. A map is used for flexibility with any character set.
        // For max speed in competitive programming with a fixed alphabet (e.g., 'a'-'z'),
        // a fixed-size array ll next[26] is faster.
        map<char, ll> next; 
    };

    vector<State> sa; // Vector to store all states of the automaton.
    vector<ll> first_pos;   // The first occurrence ending index of the state.
    vector<bool> is_terminal; // Marks terminal states (suffix states)
    vector<ll> occ_count;   // Occurrence count for the state.
    vector<ll> distinct_substring_dp; // DP array for distinct substring counting

    ll size;             // The current number of states in the automaton.
    ll last_state;       // The state corresponding to the full string processed so far.

    // Sorts states in descending order of length (for topological processing)
    vector<ll> get_sorted_states_by_length_descending() {
        vector<ll> order(size);
        for (ll i = 0; i < size; i++) {
            order[i] = i;
        }
        sort(order.begin(), order.end(), [&](ll a, ll b) {
            return sa[a].len > sa[b].len;
        });
        return order;
    }

    vector<ll> state_cost;

public:
    /**
     * @brief Constructs a SuffixAutomaton, preparing it for a string of max_len.
     * @param max_len The maximum expected length of the string to be processed.
     *                This helps in pre-allocating memory to avoid reallocations.
     */
    SuffixAutomaton(ll max_len) {
        // A string of length N has at most 2N-1 states for N>=2.
        // We allocate 2*max_len + 2 for a safe buffer.
        ll max_states = max_len * 2 + 2;
        sa.resize(max_states);
        first_pos.resize(max_states, -1);
        is_terminal.resize(max_states, false);
        occ_count.resize(max_states, 0);
        distinct_substring_dp.resize(max_states, -1); // -1 = not computed
        state_cost.resize(max_states, 0);
        // Initialize the automaton to its base state.
        reset();
    }

    /**
     * @brief Resets the automaton to its initial state, ready for a new string.
     */
    void reset() {
        // The automaton starts with a single root state at index 0.
        size = 1;
        last_state = 0;

        // Configure the root state.
        sa[0].len = 0;
        sa[0].link = -1; // -1 denotes a null link.
        sa[0].next.clear();
        first_pos[0] = -1;   // empty string has no position
        occ_count[0] = 0;
        is_terminal[0] = false;
        distinct_substring_dp.assign(sa.size(), -1); // reset DP
    }

    /**
     * @brief Extends the automaton by adding a single character. This is the core algorithm.
     * @param c The character to add.
     */
    void extend(char c) {
        // 1. Create a new state current_state for the new, extended string.
        ll current_state = size++;
        sa[current_state].len = sa[last_state].len + 1;
        sa[current_state].next.clear();
        first_pos[current_state] = sa[current_state].len - 1; // 0-indexed position
        occ_count[current_state] = 1; // new state represents one occurrence
        distinct_substring_dp[current_state] = -1; // mark DP as invalid

        // 2. Traverse suffix links from last_state
        ll p = last_state;
        while (p != -1 && sa[p].next.find(c) == sa[p].next.end()) {
            sa[p].next[c] = current_state;
            p = sa[p].link;
        }

        // 3. Set suffix link for current_state
        if (p == -1) {
            sa[current_state].link = 0;
        } else {
            ll q = sa[p].next[c];
            if (sa[q].len == sa[p].len + 1) {
                sa[current_state].link = q;
            } else {
                // Clone state q to mallain automaton properties
                ll clone = size++;
                sa[clone] = sa[q]; // copy all fields
                sa[clone].len = sa[p].len + 1;
                first_pos[clone] = first_pos[q]; // same first occurrence
                occ_count[clone] = 0; // clone starts with 0 occurrences
                distinct_substring_dp[clone] = -1; // mark DP as invalid

                // Redirect transitions to the clone
                while (p != -1 && sa[p].next[c] == q) {
                    sa[p].next[c] = clone;
                    p = sa[p].link;
                }
                sa[q].link = clone;
                sa[current_state].link = clone;
            }
        }
        last_state = current_state;
    }

    /**
     * @brief Build automaton for an entire string (optionally finalize)
     * @param s The string to build the automaton from.
     * @param finalize Whether to compute terminal states and occurrence counts
     */
    void build_for_string(const string& s, bool finalize = true) {
        reset();
        for (char c : s) {
            extend(c);
        }
        if (finalize) finalize_automaton();
    }

    /**
     * @brief Build automaton for multiple strings separated by a character
     * @param strs Vector of strings to process
     * @param separator Character not in any string (for separation)
     */
    void build_for_strings(const vector<string>& strs, char separator) {
        reset();
        for (const auto& s : strs) {
            for (char c : s) {
                extend(c);
            }
            extend(separator);
        }
    }

    /**
     * @brief Finalize automaton by computing terminal states and occurrences
     */
    void finalize_automaton() {
        compute_occurrence_counts();
        mark_terminal_states();
    }

    /**
     * @brief Compute occurrence counts via topological sort
     */
    void compute_occurrence_counts() {
        vector<ll> order = get_sorted_states_by_length_descending();
        for (ll state : order) {
            if (sa[state].link != -1) {
                occ_count[sa[state].link] += occ_count[state];
            }
        }
    }

    /**
     * @brief Mark terminal states (suffix states)
     */
    void mark_terminal_states() {
        ll p = last_state;
        while (p != -1) {
            is_terminal[p] = true;
            p = sa[p].link;
        }
    }

    /**
     * @brief Precompute DP for distinct substring counting
     */
    void precompute_distinct_substrings_dp() {
        distinct_substring_dp.assign(size, -1); // reset
        vector<ll> order = get_sorted_states_by_length_descending();

        for (ll state : order) {
            distinct_substring_dp[state] = 0;
            for (const auto& edge : sa[state].next) {
                ll next = edge.second;
                distinct_substring_dp[state] += 1 + distinct_substring_dp[next];
            }
        }
    }

    /**
     * @brief Check if substring exists in automaton
     * @param s Substring to search for
     * @return True if substring exists
     */
    bool contains_substring(const string& s) {
        ll state = 0;
        for (char c : s) {
            auto it = sa[state].next.find(c);
            if (it == sa[state].next.end()) return false;
            state = it->second;
        }
        return true;
    }

    /**
     * @brief Count distinct substrings in the string
     * @return Number of distinct substrings
     */
    ll count_distinct_substrings() {
        ll total = 0;
        for (ll i = 1; i < size; i++) {
            total += sa[i].len - sa[sa[i].link].len;
        }
        return total;
    }

    /**
     * @brief Calculate total length of all distinct substrings
     * @return Total length across all distinct substrings
     */
    ll total_length_distinct_substrings() {
        ll total = 0;
        for (ll i = 1; i < size; i++) {
            ll min_len = sa[sa[i].link].len + 1;
            ll max_len = sa[i].len;
            total += (max_len*(max_len+1))/2 - ((min_len-1)*min_len)/2;
        }
        return total;
    }

    /**
     * @brief Find k-th lexicographically smallest distinct substring
     * @param k Position in lex order (1-indexed)
     * @return k-th smallest substring
     */
    string kth_distinct_substring(ll k) {
        if (distinct_substring_dp[0] == -1) {
            precompute_distinct_substrings_dp();
        }
        if (k < 1 || k > distinct_substring_dp[0]) return "";

        string result;
        ll state = 0;
        while (k > 0) {
            for (const auto& edge : sa[state].next) {
                char c = edge.first;
                ll next_state = edge.second;
                ll count = 1 + distinct_substring_dp[next_state];
                
                if (k <= count) {
                    result += c;
                    k--;
                    state = next_state;
                    break;
                } else {
                    k -= count;
                }
            }
        }
        return result;
    }

    /**
     * @brief Finds the length of the Longest Common Substring (LCS) between the
     *        string this automaton was built on (s1) and another string (s2).
     * @param s2 The second string to compare against.
     * @return The length of the LCS.
     */
    ll longest_common_substring(const string& s2) {
        ll best_len = 0;              // Stores the maximum length found so far.
        ll current_match_len = 0;     // Length of the current continuous match from s2.
        ll current_state = 0;         // The current state in the automaton we are at.

        // Iterate through the second string, character by character.
        for (char c : s2) {
            // --- The Mismatch Handling Logic ---
            // While we are not at the root and there is no transition for the
            // character 'c' from our current state, we have a mismatch.
            while (current_state != 0 && sa[current_state].next.find(c) == sa[current_state].next.end()) {
                // We can't extend the current match. So, we shorten it by
                // jumping to the state of its longest proper suffix via the suffix link.
                current_state = sa[current_state].link;
                // Our match length is now, at most, the length of this new state.
                current_match_len = sa[current_state].len;
            }

            // --- The Match Extension Logic ---
            // After the while loop, we check if a transition for 'c' exists from our
            // (possibly new) current_state.
            if (sa[current_state].next.count(c)) {
                // A transition exists! We can extend our match.
                current_state = sa[current_state].next.at(c);
                current_match_len++;
            } else {
                // Even from the root, no transition exists. This means the character 'c'
                // doesn't start any match. We are fully reset.
                // The 'while' loop above already guarantees that current_state is 0
                // and current_match_len is 0 in this case, so no code is needed here.
            }
            
            // After processing each character, update our overall best result.
            best_len = std::max(best_len, current_match_len);
        }

        return best_len;
    }

    /**
     * @brief Pre-computes the cost (sum of ASCII values) for the longest string
     *        of each state. This is needed for cost-based problems.
     */
    void compute_state_costs() {
        // We can do a simple BFS from the root to compute costs topologically.
        vector<int> q;
        q.push_back(0);

        vector<bool> visited(size, false);
        visited[0] = true;
        
        state_cost.assign(size, 0);

        int head = 0;
        while(head < q.size()){
            int u = q[head++];
            for(const auto& edge : sa[u].next){
                char c = edge.first;
                int v = edge.second;
                if(!visited[v]){
                    // Cost of child = Cost of parent + ASCII value of transition char
                    state_cost[v] = state_cost[u] + static_cast<int>(c);
                    visited[v] = true;
                    q.push_back(v);
                }
            }
        }
    }

    long long longest_common_substring_by_cost(const std::string& s2) {
        // --- PRE-COMPUTATION STEP ---
        // This is the crucial new part. We must have the costs ready.
        compute_state_costs();

        long long best_cost = 0;
        long long current_match_cost = 0;
        int current_state = 0;

        for (char c : s2) {
            // Mismatch loop
            while (current_state != 0 && sa[current_state].next.find(c) == sa[current_state].next.end()) {
                current_state = sa[current_state].link;
                // **THE KEY CHANGE IS HERE**
                // Instead of updating length, we look up the pre-computed cost
                // for the state we jumped to.
                current_match_cost = state_cost[current_state];
            }

            // Match extension
            if (sa[current_state].next.count(c)) {
                current_state = sa[current_state].next.at(c);
                // **THE OTHER KEY CHANGE**
                // We add the ASCII value of the new character to our running cost.
                current_match_cost += static_cast<int>(c);
            } else {
                // Total mismatch, reset cost.
                current_match_cost = 0;
            }
            
            best_cost = std::max(best_cost, current_match_cost);
        }

        return best_cost;
    }

    /**
     * @brief Debug prll automaton state details
     */
    void debug_prll() {
        cout << "--- Suffix Automaton State Dump ---" << endl;
        cout << "Total states: " << size << endl;
        cout << "Final state (last_state): " << last_state << endl;
        for (ll i = 0; i < size; ++i) {
            cout << "State " << i << " | ";
            cout << "Length: " << sa[i].len << " | ";
            cout << "Suffix Link: " << sa[i].link << " | ";
            cout << "First Pos: " << first_pos[i] << " | ";
            cout << "Terminal: " << (is_terminal[i] ? "T" : "F") << " | ";
            cout << "Occ Count: " << occ_count[i] << " | ";
            cout << "DP: " << distinct_substring_dp[i] << " | ";
            cout << "Transitions: { ";
            for (const auto& edge : sa[i].next) {
                cout << edge.first << "->" << edge.second << " ";
            }
            cout << "}" << endl;
        }
        cout << "-----------------------------------" << endl;
    }
};

/*################ Code #################*/

TOXOTIS
{
    // Fast_IO
    
}