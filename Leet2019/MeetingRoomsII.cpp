#include "stdafx.h"
//Given an array of meeting time intervals consisting of start and end 
//times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of 
//conference rooms required.
//
//Example 1:
//Input: [[0, 30],[5, 10],[15, 20]]
//Output: 2
//
//Example 2:
//Input: [[7,10],[2,4]]
//Output: 1
//
//NOTE: input types have been changed on April 15, 2019. 
//Please reset to default code definition to get new method signature.

namespace Solution2019
{
	namespace MeetingRoomsII
	{
		int minMeetingRooms(vector<vector<int>>& intervals) {
			vector<pair<int, int>> meetings;
			for (vector<int>& interval : intervals) {
				meetings.push_back({ interval[0], 1 });
				meetings.push_back({ interval[1], -1 });
			}
			sort(meetings.begin(), meetings.end());
			int room = 0;
			int maxRoom = 0;
			for (pair<int, int>& p : meetings) {
				room += p.second;
				maxRoom = max(maxRoom, room);
			}
			return maxRoom;
		}


		namespace Another {
			void helper(vector<vector<int>>& intervals, int& result) {
				vector<vector<int>> overlap;
				vector<int> last = intervals[0];
				for (int i = 1; i < intervals.size(); i++) {
					if (last[1] > intervals[i][0]) {
						overlap.push_back(intervals[i]);
					}
					else {
						last = intervals[i];
					}
				}
				if (!overlap.empty()) {
					result++;
					helper(overlap, result);
				}
			}

			int minMeetingRooms(vector<vector<int>>& intervals) {
				int len = intervals.size();
				if (len < 2) { return len; }
				auto comp = [](vector<int>& a, vector<int>& b) {
					if (a[0] == b[0]) { return a[1] < b[1]; }
					return a[0] < b[0];
				};

				sort(intervals.begin(), intervals.end(), comp);
				int result = 1;
				helper(intervals, result);
				return result;
			}
		}
		void Main() {
			vector<vector<int>> test = { {7,10},{2,4} };
			print(minMeetingRooms(test));
		}
	}
}

