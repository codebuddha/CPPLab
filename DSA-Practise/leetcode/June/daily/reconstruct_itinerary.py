from typing import List
# import traceback as tb
def track(start, map_dict, length):
    res, sub_res = [start], []
    print("res", res)
    j = -1
    for dest in map_dict[start]:
        j += 1
        if length == 1:
            res.append(dest)
            return res
        if dest in list(map_dict.keys()):
            next_start = dest
            curr_dests = map_dict[start]
            map_dict[start] = map_dict[start][:j] + map_dict[start][j+1:]
            sub_res = track(next_start, map_dict, length-1)
            print("sub res", sub_res)
            if sub_res is None or len(sub_res) == 0:
                map_dict[start] = curr_dests
                continue 
            else:
                break
        if sub_res is None or len(sub_res) == 0:
            return []
        else:
            res.extend(sub_res)
            return res

def findItinerary(tickets: List[List[str]]):
    if len(tickets) == 0:
        return ["JFK"]
    map_dict = {}
    # print(map_dict)
    result = []
    for l in tickets:
        try:
            map_dict[l[0]].add(l[1])
        except KeyError:
            map_dict[l[0]] = {l[1]}
    map_dict = {k: sorted(v) for k,v in map_dict.items()}
    print("start ", map_dict)
    start = 'JFK'
    result = track(start, map_dict, len(tickets))
    return result

if __name__ == "__main__":
    itin = [
        [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]],
        [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]],
        [["JFK", "ATL"], ["ATL", "JFK"]],
        # [],
        # [["JFK", "JFK"]]
        [["JFK", "KUL"], ["JFK", "NRT"], ["NRT", "JFK"]]
    ]
    for i, it in enumerate(itin): 
        print("*"*100)
        print(i, findItinerary(it))