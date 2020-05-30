#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int>& input);
bool checkCorrect(std::vector<int>& input);

int main(){

    using namespace std;

    vector<int> oneNine;
    for(int i = 1;i<10;i++){
        oneNine.push_back(i);
    }
    int sz = 1;
    for(int i = 9; i>0;i--){
        sz*= i;
    }
    for(int i = 0; i<sz;i++){
        if(checkCorrect(oneNine)){
            printf(" %d%d\n* %d\n----\n %d%d\n+%d%d\n----\n %d%d\n",oneNine[0],oneNine[1],oneNine[2],oneNine[3],oneNine[4],oneNine[5],oneNine[6],oneNine[7],oneNine[8]);
        }
        nextPermutation(oneNine);
    }
    
    
    return 0;
}

void nextPermutation(std::vector<int>& nums) {

    using namespace std;

    if(nums.empty()||nums.size()==1){
        return;
    }
    
    int index = nums.size()-2;
    while(index>=0 && nums.back()<=nums[index]){
        int temp = nums[index];
        nums[index] = nums.back();
        nums.back() = temp;
        index--;
    }
    if(index == -1){
        sort(nums.begin(),nums.end());
        return;
    }
    if(nums[index]<nums.back()){
        
        auto iterS = nums.begin()+index+1;
        auto iterE = nums.end();
        sort(iterS,iterE);
        for(int i = index+1;i<(int)nums.size();i++){
            if(nums[i]>nums[index]){
                int temp = nums[index];
                nums[index] = nums[i];
                nums[i] = temp;
                break;
            }
        }   
    }    
}

bool checkCorrect(std::vector<int>& nums){
    if (nums.empty()){
        return 0;
    }
    int line1 = nums[0]*10+nums[1];
    int line2 = nums[2];
    int line3 = nums[3]*10+nums[4];
    //printf(" %d%d\n* %d\n----\n %d%d\n\n",nums[0],nums[1],nums[2],nums[3],nums[4]);
    if(!((line1*line2)==line3)){
        return 0;
    }
    //printf("did i ever get past?");
    int line4 = nums[5]*10+nums[6];
    int line5 = nums[7]*10+nums[8];
    return ((line3+line4)==line5);

}