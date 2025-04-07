#ifndef STATECONVERTER_H
#define STATECONVERTER_H

#include <string>

enum class QuicktelStatus {
    SUCCESSFUL,      
    IN_PROGRESS,
    WRITE_COMPLETE,   
    SYNC_WAITING, 
    BACKUP_RUNNING,
    CANCELLED,
    UNKNOWN_STATUS
};

// Our application states
enum class ApplicationState {
    SUCCESS,
    UPDATE_ONGOING,
    WRITE_DONE,
    SYNC_WAITING,
    BACKUP_ONGOING,
    OPERATION_CANCELLED,
    INVALID_STATUS
};

class StateConverter {
public:
    // Only allow exact string matches
    static ApplicationState convertToAppState(const std::string& quicktelStatus);
    
    // Alternative enum mapping
    static ApplicationState convertToAppState(QuicktelStatus quicktelStatus);
};

#endif // STATECONVERTER_H
