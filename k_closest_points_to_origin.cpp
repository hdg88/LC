class Solution {
public:
    double calcDistanceFromZero(vector<int> coords) {
        return sqrt(pow(coords[0], 2.0) + pow(coords[1], 2.0));
    }
    /*
    The idea here is that we calculate all the distances and use these
      as a key in an ordered map (this is a map that stores data in 
      ascending order by key). Once we calculate all the distances, we 
      can then loop through all the items in the map untill the size
      of the resultant map reaches a size of k. Since the map is ordered
      we can guarantee that the first k points will be in order as well.
      
      If 2 points have the same distance, for that key in the map we 
      store points as a vector, (so the map value is a vector of vectors). 
    */
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<double, vector<vector<int>>> tracker;
        map<double, vector<vector<int>>>::iterator trackerit;

        for (int i = 0; i<points.size(); i++) {
            double dist = calcDistanceFromZero(points[i]);
            tracker[dist].push_back(points[i]);
        }

        vector<vector<int>> result;

        for (trackerit = tracker.begin(); trackerit!=tracker.end(); trackerit++) {
            for (int i = 0; i< trackerit->second.size(); i++) {
                if (result.size() == k) return result;
                result.push_back(trackerit->second[i]);
            }
        }
        return result;
    }
};
