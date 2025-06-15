// Flipping an Image (#832)

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        
        // Loop through each row in the matrix
        for (int i = 0; i < n; ++i) {
            int left = 0;
            int right = n - 1;

            // Two-pointer approach to reverse and invert simultaneously
            while (left <= right) {
                // Swap and invert elements at left and right
                // XOR with 1 inverts the bits: 0^1 = 1, 1^1 = 0
                int tempLeft = image[i][left] ^ 1;
                int tempRight = image[i][right] ^ 1;

                // Swap inverted values
                image[i][left] = tempRight;
                image[i][right] = tempLeft;

                ++left;
                --right;
            }
        }
        return image;
    }
};