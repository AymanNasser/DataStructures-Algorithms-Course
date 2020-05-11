class Solution {
public:
void auxiFloodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor){

    // if the col or row index exccedes the col or row size or == (-ve) value so return
    // also if the current pixel != older color also return
	if(sr < 0 || sc < 0 || (sr >= image.size()) || (sc >= image[sr].size()) || image[sr][sc] !=oldColor )
		return;


	image[sr][sc] = newColor;

    // Recursing on the 4-directions of each pixel
	auxiFloodFill(image, sr, sc+1, newColor, oldColor);
	auxiFloodFill(image, sr, sc-1, newColor, oldColor);

	auxiFloodFill(image, sr+1, sc, newColor, oldColor);
	auxiFloodFill(image, sr-1, sc, newColor, oldColor);



}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL); 
    // If the source pixel has the new color so we've no work to do
    if(image[sr][sc] == newColor)
        return image;
    // else call auxiliary fill function & pass the old color to check by 
	auxiFloodFill(image, sr, sc, newColor, image[sr][sc]);

	return image;

}
};
