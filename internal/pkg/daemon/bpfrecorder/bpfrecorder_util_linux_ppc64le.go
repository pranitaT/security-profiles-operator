//go:build ppc64le && linux
// +build ppc64le,linux

/*
Copyright 2024 The Kubernetes Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

package bpfrecorder

import "syscall"

// Note: "sys_exit_clone" This feature is not supported in kernel versions prior to 5.7,
// as it depends on the BPF_LINK_CREATE structure introduced in that version.
// For further details, please refer to the documentation: https://docs.ebpf.io/linux/syscall/BPF_LINK_CREATE/
// 
// TODO: We may consider adding conditional logic to filter kernel versions 
// based on their major and minor version, to selectively enable or disable 
// certain hooks depending on the kernel's capabilities and support.
// getBaseHooks returns the list of base hooks.
func getBaseHooks() []string {
    return []string{
        "sys_enter",
        // "sys_exit_clone",
        "sys_enter_execve",
        "sys_enter_getgid",
        "sys_enter_prctl",
        "sched_process_exec",
        "sched_process_exit",
    }
}

// UnameMachineToString converts uname.Machine to a string for s390x/ppc64le.
func UnameMachineToString(uname *syscall.Utsname) string {
	return toStringUint8P(uname.Machine)
}

// UnameReleaseToString converts uname.Release to a string for s390x/ppc64le.
func UnameReleaseToString(uname *syscall.Utsname) string {
	return toStringUint8P(uname.Release)
}

// Helper function to convert [65]uint8 to string.
func toStringUint8P(array [65]uint8) string {
	n := 0
	for i, v := range array {
		if v == 0 {
			n = i
			break
		}
	}
	return string(array[:n])
}
