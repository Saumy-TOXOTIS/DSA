#include "template.hpp"
ll n, m;
const ll N = 2e5;
vector<pair<ll,ll>> graph[N + 1];

/*########### Extra Functions ###########*/

//usually used in dynamic graphs
class Disjoint_Set
{
    private:
    vector<ll> union_rank;
    vector<ll> union_size;
    vector<ll> parent;
    public:
    Disjoint_Set(ll n)
    {
        union_rank.resize(n + 1,0);
        union_size.resize(n + 1);
        parent.resize(n + 1);
        for(ll i = 0;i < n + 1;i++)
        {
            union_size[i] = 1;
            parent[i] = i;
        }
    }
    ll find_parent(ll node)
    {
        if(node == parent[node])
        {
            return node;
        }
        return (parent[node] = find_parent(parent[node]));
    }
    void union_by_rank(ll node_1,ll node_2)
    {
        ll parent_node_1 = find_parent(node_1);
        ll parent_node_2 = find_parent(node_2);
        if(parent_node_1 == parent_node_2)
        {
            return;
        }
        if(union_rank[parent_node_1] < union_rank[parent_node_2])
        {
            parent[parent_node_1] = parent_node_2;
        }
        else if(union_rank[parent_node_1] > union_rank[parent_node_2])
        {
            parent[parent_node_2] = parent_node_1;
        }
        else
        {
            parent[parent_node_2] = parent_node_1;
            union_rank[parent_node_1]++;
        }
    }
    void union_by_size(ll node_1,ll node_2)
    {
        ll parent_node_1 = find_parent(node_1);
        ll parent_node_2 = find_parent(node_2);
        if(parent_node_1 == parent_node_2)
        {
            return;
        }
        if(union_size[parent_node_1] < union_size[parent_node_2])
        {
            parent[parent_node_1] = parent_node_2;
            union_size[parent_node_2] += union_size[parent_node_1];
        }
        else if(union_size[parent_node_1] > union_size[parent_node_2])
        {
            parent[parent_node_2] = parent_node_1;
            union_size[parent_node_1] += union_size[parent_node_2];
        }
        else
        {
            parent[parent_node_2] = parent_node_1;
            union_size[parent_node_1] += union_size[parent_node_2];
        }
    }
};

/*################ Code #################*/

TOXOTIS
{
    // Fast_IO
    cin>>n>>m;
    Disjoint_Set DS_rank(n), DS_size(n);
    f1(i,0,m,1)
    {
        d_ll(U) d_ll(V) d_ll(W)
        graph[U].push_back({V,W});
        graph[V].push_back({U,W});
        DS_rank.union_by_rank(U,V);
        DS_size.union_by_size(U,V);
    }
}