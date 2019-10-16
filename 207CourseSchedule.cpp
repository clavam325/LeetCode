class Solution {
public:
    
    vector<list<int> > courseList;
    bool isPossible(int vertex, vector<bool>& visited, vector<bool>& recStack ) {
    	
    	if(!visited[vertex]){
    		visited[vertex] = true;
    		recStack[vertex] = true;

    		for(auto preReq : courseList[vertex]) {
    			if(!visited[preReq]){
    				if(isPossible(preReq, visited, recStack))
    					return false;
    			}
    			else if(recStack[preReq] == true)
    				return false;
    		}

    	}
    	recStack[vertex] = false;
    	return true;
    }
     
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	courseList.resize(numCourses);
    	list<int> preReqList;

    	vector<bool> visited(numCourses, false), recStack(numCourses, false);
        for(auto course : prerequisites) {
        	if(course.size() == 2){
        		courseList[course[0]].push_back(course[1]);
        	}
        }

        for(int i = 0 ; i < numCourses; i++ ) {
        	if(isPossible(i, visited, recStack))
        		return true;            
        }
        return false;
     }
};