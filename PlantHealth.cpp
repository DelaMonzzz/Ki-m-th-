#include <iostream>
#include <string>
using namespace std;

string plantStatus(double soilMoisture, double sunlight) {
    string moistureCat;
    string lightCat;

    if (soilMoisture < 0 || soilMoisture > 100) {
        moistureCat = "lỗi";
    } else if (soilMoisture < 30) {
        moistureCat = "khô hạn";
    } else if (soilMoisture <= 70) {
        moistureCat = "bình thường";
    } else {
        moistureCat = "quá ẩm";
    }

    if (sunlight < 0 || sunlight > 24) {
        lightCat = "lỗi";
    } else if (sunlight < 4) {
        lightCat = "thiếu sáng";
    } else if (sunlight <= 8) {
        lightCat = "đủ sáng";
    } else {
        lightCat = "quá nắng";
    }

    if (moistureCat == "lỗi" || lightCat == "lỗi") {
        return "Input không hợp lệ";
    } else if (moistureCat == "bình thường" && lightCat == "đủ sáng") {
        return "Khỏe mạnh";
    } else if ((moistureCat == "khô hạn" && lightCat == "thiếu sáng")
            || (moistureCat == "khô hạn" && lightCat == "quá nắng")
            || (moistureCat == "quá ẩm" && lightCat == "quá nắng")
            || (moistureCat == "quá ẩm" && lightCat == "thiếu sáng")) {
        return "Yếu";
    } else {
        return "Phát triển bình thường";
    }
}

int main() {
    double soilMoisture, sunlight;

    cout << "Nhập độ ẩm đất (%): ";
    cin >> soilMoisture;

    cout << "Nhập số giờ nắng trong ngày: ";
    cin >> sunlight;

    string result = plantStatus(soilMoisture, sunlight);
    cout << "Kết quả đánh giá: " << result << endl;

    return 0;
}