//go:build amd64 && linux
// +build amd64,linux

package daemon

import "syscall"

// UnameMachineToString converts uname.Machine to a string for amd64.
func UnameMachineToString(uname syscall.Utsname) string {
    return toStringInt8(uname.Machine)
}

// UnameReleaseToString converts uname.Release to a string for amd64.
func UnameReleaseToString(uname syscall.Utsname) string {
    return toStringInt8(uname.Release)
}

// Helper function to convert [65]int8 to string.
func toStringInt8(i [65]int8) string {
    n := 0
    for idx, val := range i {
        if val == 0 {
            n = idx
            break
        }
    }
    return string(i[:n])
}
