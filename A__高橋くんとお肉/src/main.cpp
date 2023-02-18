#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;



int main( int argc, char** argv ){
    int n;
    cin >> n;

    int sum = 0;

    std::vector<int> nums( n );
    for( int i = 0; i < n; i++ ){
        cin >> nums[i];
        sum += nums[i];
    }

    int time_min = 250;

    for( int bit = 1; bit < (1 << n); ++bit ){
        int plate1 = 0, plate2 = 0;
        for( int i = 0; i < n; ++i ){
            if( bit & (1 << i) ){
                plate1 += nums[i];
            }else{
                plate2 += nums[i];
            }

            // すべて焼けていないとダメ
            if( sum != (plate1 + plate2) ) continue;

            // プレート1, プレート2 の一番時間がかかってる方を選択する
            int plate_max = std::max( plate1, plate2 );

            time_min = std::min( time_min, plate_max );
        }
    }

    cout << time_min << endl;
return 0;
}
