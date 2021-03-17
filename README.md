# PSS_University_Access_System.


Exit, exit, out - for exit from program.
Login - to login in system (Name : Admin, Password : toor)

# Show information about users by name and surname
GetStudent - show user by Name and Surname
GetLabEmployees - show user by Name and Surname
GetProfessor - show user by Name and Surname
GetGuest - show user by Name and Surname - new
GetLabEmployeer - show user by Name and Surname
GetAdmin - show user by Name and Surname

ShawAllUsers - Showing all users (id, name ,surname).
ShowAllRooms - Showing all rooms (number,Label,access level).

# Add User and Room into system
AddNewUser - adding new user :
  For a student a special parameter is the year in which he entered university and group number.
  For admin a special parameter is password.
  For a professor a special parameter is subject.
  For Lab Employees a special parameter is subject.
AddNewRoom - add new room with Name, room number, and Access level.

# Change Access in the system
CanUserEnter - writing possibility that user can enter. User finding by Name and surname and room finding by room number.
AddSpecialAccess - adding user to special list. All users from this list can enter this room.
RemoveSpecialAccess - removing users from this list.

# Changing Groups 
ChangeGroupsForLabEmployees - sends a list of groups in which this assistant will conduct labs.
ChangeGroupForStudent - change group with which student will study.

# Deleting User from system
DeleteUser - deleting user by name and surname - new.
