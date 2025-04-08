#include "StateConverter.h"

ApplicationState StateConverter::convertToAppState(const std::string& quicktelStatus) {
    if (quicktelStatus == "SUCCESSFUL") return ApplicationState::SUCCESS;
    if (quicktelStatus == "IN_PROGRESS") return ApplicationState::UPDATE_ONGOING;
    if (quicktelStatus == "WRITE_COMPLETE") return ApplicationState::WRITE_DONE;
    if (quicktelStatus == "SYNC_WAITING") return ApplicationState::SYNC_WAITING;
    if (quicktelStatus == "BACKUP_RUNNING") return ApplicationState::BACKUP_ONGOING;
    if (quicktelStatus == "CANCELLED") return ApplicationState::OPERATION_CANCELLED;
    return ApplicationState::INVALID_STATUS;
}

ApplicationState StateConverter::convertToAppState(QuicktelStatus quicktelStatus) {
    switch (quicktelStatus) {
        case QuicktelStatus::SUCCESSFUL: return ApplicationState::SUCCESS;
        case QuicktelStatus::IN_PROGRESS: return ApplicationState::UPDATE_ONGOING;
        case QuicktelStatus::WRITE_COMPLETE: return ApplicationState::WRITE_DONE;
        case QuicktelStatus::SYNC_WAITING: return ApplicationState::SYNC_WAITING;
        case QuicktelStatus::BACKUP_RUNNING: return ApplicationState::BACKUP_ONGOING;
        case QuicktelStatus::CANCELLED: return ApplicationState::OPERATION_CANCELLED;
        default: return ApplicationState::INVALID_STATUS;
    }
}
