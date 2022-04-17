#include <algorithm>
using namespace std;

struct CourseNode{
    bool learned = false;
    vector<CourseNode*> parentNodes;
    vector<CourseNode*> childNodes;
}; // course 정보를 저장: 수강 여부, 선이수강좌, 후이수강좌
    
void courseSearch(CourseNode* Node){
    if(!Node->parentNodes.empty()) return; // 선이수강좌를 모두 들은 경우, 선이수강좌가 없는 경우
    Node->learned = true; // 수강 완료
    if(Node->childNodes.empty()) return; // 후이수강좌가 없는 경우 리턴
    for(CourseNode* childNode : Node->childNodes) // 후이수강좌에 대해 선이수 완료를 적용
        childNode->parentNodes.erase(find(childNode->parentNodes.begin(), childNode->parentNodes.end(), Node));
    while(!Node->childNodes.empty()){ // 후이수강좌에 대해 courseSearch 반복
        courseSearch(Node->childNodes.back());
        Node->childNodes.pop_back();
    }
}    
    
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    CourseNode* CourseGraph = new struct CourseNode[numCourses]; // 직접 메모리 할당 필요
    for(vector<int> constraint : prerequisites){ // CourseGraph 작성
        (CourseGraph+constraint[0])->parentNodes.push_back(CourseGraph+constraint[1]);
        (CourseGraph+constraint[1])->childNodes.push_back(CourseGraph+constraint[0]);
    }
        
    for(int i=0;i<numCourses;i++)
        courseSearch(CourseGraph+i); // 수강가능 여부 탐색
        
    for(int i=0;i<numCourses;i++)
        if(!CourseGraph[i].learned) return false;
    return true;
}
