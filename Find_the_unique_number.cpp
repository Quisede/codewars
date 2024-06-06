// There is an array with some numbers. All numbers are equal except for one. Try to find it!

// find_uniq(std::vector<float>{1, 1, 1, 2, 1, 1});  // --> 2
// find_uniq(std::vector<float>{0, 0, 0.55, 0, 0});  // --> 0.55
// It’s guaranteed that array contains at least 3 numbers.

// The tests contain some very huge arrays, so think about performance.

float find_uniq(const std::vector<float> &v)
{
    // Check first two elements
    if (v[0] != v[1]) {
        if (v[0] == v[2]) {
            // v[0] is the unique element
            return v[1];
        } else {
            // v[1] is the unique element
            return v[0];
        }
    }

    // If we're here, then the first two elements are equal
    // So, we need to find the different one
    for (size_t i = 2; i < v.size(); i++) {
        if (v[i] != v[0]) {
            // v[i] is the unique element
            return v[i];
        }
    }

    // If no unique element found, return 0
    return 0;
}