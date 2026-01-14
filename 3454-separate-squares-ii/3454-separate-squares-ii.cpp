class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        struct Event {
            int y;
            int type; 
            int xStart;
            int xEnd;


            bool operator<(const Event& other) const { return y < other.y; }
        };

        struct Strip {
            int y;
            int height;
            double unionWidth;
        };

        vector<Event> sweepEvents;
        for (const auto& sq : squares) {
            int x = sq[0];
            int y = sq[1];
            int l = sq[2];
            sweepEvents.push_back({y, 1, x, x + l});
            sweepEvents.push_back({y + l, -1, x, x + l});
        }

        sort(sweepEvents.begin(), sweepEvents.end());

        vector<pair<int, int>> activeIntervals;
        vector<Strip> processedStrips;
        double totalArea = 0;
        int prevY = sweepEvents[0].y;

        for (const auto& event : sweepEvents) {


            if (event.y > prevY) {
                double width = getUnionWidth(activeIntervals);
                int height = event.y - prevY;

                if (width > 0) {
                    processedStrips.push_back({prevY, height, width});
                    totalArea += (double)height * width;
                }
            }

    
            if (event.type == 1) {
                activeIntervals.push_back({event.xStart, event.xEnd});
            } else {
           
              
              
                for (auto it = activeIntervals.begin();
                     it != activeIntervals.end(); ++it) {
                    if (it->first == event.xStart && it->second == event.xEnd) {
                        activeIntervals.erase(it);
                        break;
                    }
                }
            }
            prevY = event.y;
        }

        
        double targetArea = totalArea / 2.0;
        double accumulatedArea = 0;

        for (const auto& strip : processedStrips) {
            double stripArea = strip.height * strip.unionWidth;

            if (accumulatedArea + stripArea >= targetArea) {
                double areaNeeded = targetArea - accumulatedArea;
                return strip.y + (areaNeeded / strip.unionWidth);
            }
            accumulatedArea += stripArea;
        }

        return 0.0;
    }

private:
  
    double getUnionWidth(vector<pair<int, int>> intervals) {
        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end());

        double unionLength = 0;
        double currentEnd = -1e18; 

        for (const auto& interval : intervals) {
            double start = interval.first;
            double end = interval.second;

            if (start >= currentEnd) {
            
                unionLength += (end - start);
                currentEnd = end;
            } else if (end > currentEnd) {
            
                unionLength += (end - currentEnd);
                currentEnd = end;
            }
        }
        return unionLength;
    }
};
