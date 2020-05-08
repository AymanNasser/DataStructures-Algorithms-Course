
/* Collinear points definition:
 * three or more points that lie on a same straight line are called collinear points.
 * so to check if all points given are collinear ==> get the slope formula of 1st 2-points
 * then iteratively check if each the next points slope == 1st 2-points slope or not
 * */

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
        
	if(coordinates.size() <= 2)
		return true;

	double slope = (double)(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
	double tempSlope;


	for (int var = 2; var < coordinates.size(); ++var) {
		tempSlope = (double)(coordinates[var][1] - coordinates[var-1][1]) /
				(coordinates[var][0] - coordinates[var-1][0]);

		if(tempSlope != slope )
			return false;
	}

    return true;
    }
};
