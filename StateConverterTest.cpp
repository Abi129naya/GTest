#include "gtest/gtest.h"
#include "StateConverter.h"

TEST(StateConverterTest, ExactMatchConversions) {
    EXPECT_EQ(StateConverter::convertToAppState("SUCCESSFUL"), ApplicationState::SUCCESS);
    EXPECT_EQ(StateConverter::convertToAppState("IN_PROGRESS"), ApplicationState::UPDATE_ONGOING);
    EXPECT_EQ(StateConverter::convertToAppState("WRITE_COMPLETE"), ApplicationState::WRITE_DONE);
    EXPECT_EQ(StateConverter::convertToAppState("SYNC_WAITING"), ApplicationState::SYNC_WAITING);
    EXPECT_EQ(StateConverter::convertToAppState("BACKUP_RUNNING"), ApplicationState::BACKUP_ONGOING);
    EXPECT_EQ(StateConverter::convertToAppState("CANCELLED"), ApplicationState::OPERATION_CANCELLED);
}

TEST(StateConverterTest, InvalidStringConversions) {
    // Case variations should fail
    EXPECT_EQ(StateConverter::convertToAppState("successful"), ApplicationState::INVALID_STATUS);
    EXPECT_EQ(StateConverter::convertToAppState("Write_Complete"), ApplicationState::INVALID_STATUS);
    
    // Invalid states
    EXPECT_EQ(StateConverter::convertToAppState(""), ApplicationState::INVALID_STATUS);
    EXPECT_EQ(StateConverter::convertToAppState("INVALID"), ApplicationState::INVALID_STATUS);
    EXPECT_EQ(StateConverter::convertToAppState("SUCESSFUL"), ApplicationState::INVALID_STATUS);
    EXPECT_EQ(StateConverter::convertToAppState("123"), ApplicationState::INVALID_STATUS);
}

TEST(StateConverterTest, EnumConversions) {
    EXPECT_EQ(StateConverter::convertToAppState(QuicktelStatus::SUCCESSFUL), ApplicationState::SUCCESS);
    EXPECT_EQ(StateConverter::convertToAppState(QuicktelStatus::IN_PROGRESS), ApplicationState::UPDATE_ONGOING);
    EXPECT_EQ(StateConverter::convertToAppState(QuicktelStatus::UNKNOWN_STATUS), ApplicationState::INVALID_STATUS);
    EXPECT_EQ(StateConverter::convertToAppState(QuicktelStatus::WRITE_COMPLETE), ApplicationState::WRITE_DONE);
    EXPECT_EQ(StateConverter::convertToAppState(QuicktelStatus::SYNC_WAITING), ApplicationState::SYNC_WAITING);
    EXPECT_EQ(StateConverter::convertToAppState(QuicktelStatus::BACKUP_RUNNING), ApplicationState::BACKUP_ONGOING);
    EXPECT_EQ(StateConverter::convertToAppState(QuicktelStatus::CANCELLED), ApplicationState::OPERATION_CANCELLED);

    
}
