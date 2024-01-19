//go:build !ignore_autogenerated

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

// Code generated by controller-gen. DO NOT EDIT.

package v1alpha2

import (
	"k8s.io/apimachinery/pkg/runtime"
)

// DeepCopyInto is an autogenerated deepcopy function, copying the receiver, writing into out. in must be non-nil.
func (in Allow) DeepCopyInto(out *Allow) {
	{
		in := &in
		*out = make(Allow, len(*in))
		for key, val := range *in {
			var outVal map[ObjectClassKey]PermissionSet
			if val == nil {
				(*out)[key] = nil
			} else {
				inVal := (*in)[key]
				in, out := &inVal, &outVal
				*out = make(map[ObjectClassKey]PermissionSet, len(*in))
				for key, val := range *in {
					var outVal []string
					if val == nil {
						(*out)[key] = nil
					} else {
						inVal := (*in)[key]
						in, out := &inVal, &outVal
						*out = make(PermissionSet, len(*in))
						copy(*out, *in)
					}
					(*out)[key] = outVal
				}
			}
			(*out)[key] = outVal
		}
	}
}

// DeepCopy is an autogenerated deepcopy function, copying the receiver, creating a new Allow.
func (in Allow) DeepCopy() Allow {
	if in == nil {
		return nil
	}
	out := new(Allow)
	in.DeepCopyInto(out)
	return *out
}

// DeepCopyInto is an autogenerated deepcopy function, copying the receiver, writing into out. in must be non-nil.
func (in PermissionSet) DeepCopyInto(out *PermissionSet) {
	{
		in := &in
		*out = make(PermissionSet, len(*in))
		copy(*out, *in)
	}
}

// DeepCopy is an autogenerated deepcopy function, copying the receiver, creating a new PermissionSet.
func (in PermissionSet) DeepCopy() PermissionSet {
	if in == nil {
		return nil
	}
	out := new(PermissionSet)
	in.DeepCopyInto(out)
	return *out
}

// DeepCopyInto is an autogenerated deepcopy function, copying the receiver, writing into out. in must be non-nil.
func (in *PolicyRef) DeepCopyInto(out *PolicyRef) {
	*out = *in
}

// DeepCopy is an autogenerated deepcopy function, copying the receiver, creating a new PolicyRef.
func (in *PolicyRef) DeepCopy() *PolicyRef {
	if in == nil {
		return nil
	}
	out := new(PolicyRef)
	in.DeepCopyInto(out)
	return out
}

// DeepCopyInto is an autogenerated deepcopy function, copying the receiver, writing into out. in must be non-nil.
func (in *RawSelinuxProfile) DeepCopyInto(out *RawSelinuxProfile) {
	*out = *in
	out.TypeMeta = in.TypeMeta
	in.ObjectMeta.DeepCopyInto(&out.ObjectMeta)
	out.Spec = in.Spec
	in.Status.DeepCopyInto(&out.Status)
}

// DeepCopy is an autogenerated deepcopy function, copying the receiver, creating a new RawSelinuxProfile.
func (in *RawSelinuxProfile) DeepCopy() *RawSelinuxProfile {
	if in == nil {
		return nil
	}
	out := new(RawSelinuxProfile)
	in.DeepCopyInto(out)
	return out
}

// DeepCopyObject is an autogenerated deepcopy function, copying the receiver, creating a new runtime.Object.
func (in *RawSelinuxProfile) DeepCopyObject() runtime.Object {
	if c := in.DeepCopy(); c != nil {
		return c
	}
	return nil
}

// DeepCopyInto is an autogenerated deepcopy function, copying the receiver, writing into out. in must be non-nil.
func (in *RawSelinuxProfileList) DeepCopyInto(out *RawSelinuxProfileList) {
	*out = *in
	out.TypeMeta = in.TypeMeta
	in.ListMeta.DeepCopyInto(&out.ListMeta)
	if in.Items != nil {
		in, out := &in.Items, &out.Items
		*out = make([]SelinuxProfile, len(*in))
		for i := range *in {
			(*in)[i].DeepCopyInto(&(*out)[i])
		}
	}
}

// DeepCopy is an autogenerated deepcopy function, copying the receiver, creating a new RawSelinuxProfileList.
func (in *RawSelinuxProfileList) DeepCopy() *RawSelinuxProfileList {
	if in == nil {
		return nil
	}
	out := new(RawSelinuxProfileList)
	in.DeepCopyInto(out)
	return out
}

// DeepCopyObject is an autogenerated deepcopy function, copying the receiver, creating a new runtime.Object.
func (in *RawSelinuxProfileList) DeepCopyObject() runtime.Object {
	if c := in.DeepCopy(); c != nil {
		return c
	}
	return nil
}

// DeepCopyInto is an autogenerated deepcopy function, copying the receiver, writing into out. in must be non-nil.
func (in *RawSelinuxProfileSpec) DeepCopyInto(out *RawSelinuxProfileSpec) {
	*out = *in
	out.SpecBase = in.SpecBase
}

// DeepCopy is an autogenerated deepcopy function, copying the receiver, creating a new RawSelinuxProfileSpec.
func (in *RawSelinuxProfileSpec) DeepCopy() *RawSelinuxProfileSpec {
	if in == nil {
		return nil
	}
	out := new(RawSelinuxProfileSpec)
	in.DeepCopyInto(out)
	return out
}

// DeepCopyInto is an autogenerated deepcopy function, copying the receiver, writing into out. in must be non-nil.
func (in *SelinuxProfile) DeepCopyInto(out *SelinuxProfile) {
	*out = *in
	out.TypeMeta = in.TypeMeta
	in.ObjectMeta.DeepCopyInto(&out.ObjectMeta)
	in.Spec.DeepCopyInto(&out.Spec)
	in.Status.DeepCopyInto(&out.Status)
}

// DeepCopy is an autogenerated deepcopy function, copying the receiver, creating a new SelinuxProfile.
func (in *SelinuxProfile) DeepCopy() *SelinuxProfile {
	if in == nil {
		return nil
	}
	out := new(SelinuxProfile)
	in.DeepCopyInto(out)
	return out
}

// DeepCopyObject is an autogenerated deepcopy function, copying the receiver, creating a new runtime.Object.
func (in *SelinuxProfile) DeepCopyObject() runtime.Object {
	if c := in.DeepCopy(); c != nil {
		return c
	}
	return nil
}

// DeepCopyInto is an autogenerated deepcopy function, copying the receiver, writing into out. in must be non-nil.
func (in *SelinuxProfileList) DeepCopyInto(out *SelinuxProfileList) {
	*out = *in
	out.TypeMeta = in.TypeMeta
	in.ListMeta.DeepCopyInto(&out.ListMeta)
	if in.Items != nil {
		in, out := &in.Items, &out.Items
		*out = make([]SelinuxProfile, len(*in))
		for i := range *in {
			(*in)[i].DeepCopyInto(&(*out)[i])
		}
	}
}

// DeepCopy is an autogenerated deepcopy function, copying the receiver, creating a new SelinuxProfileList.
func (in *SelinuxProfileList) DeepCopy() *SelinuxProfileList {
	if in == nil {
		return nil
	}
	out := new(SelinuxProfileList)
	in.DeepCopyInto(out)
	return out
}

// DeepCopyObject is an autogenerated deepcopy function, copying the receiver, creating a new runtime.Object.
func (in *SelinuxProfileList) DeepCopyObject() runtime.Object {
	if c := in.DeepCopy(); c != nil {
		return c
	}
	return nil
}

// DeepCopyInto is an autogenerated deepcopy function, copying the receiver, writing into out. in must be non-nil.
func (in *SelinuxProfileSpec) DeepCopyInto(out *SelinuxProfileSpec) {
	*out = *in
	out.SpecBase = in.SpecBase
	if in.Inherit != nil {
		in, out := &in.Inherit, &out.Inherit
		*out = make([]PolicyRef, len(*in))
		copy(*out, *in)
	}
	if in.Allow != nil {
		in, out := &in.Allow, &out.Allow
		*out = make(Allow, len(*in))
		for key, val := range *in {
			var outVal map[ObjectClassKey]PermissionSet
			if val == nil {
				(*out)[key] = nil
			} else {
				inVal := (*in)[key]
				in, out := &inVal, &outVal
				*out = make(map[ObjectClassKey]PermissionSet, len(*in))
				for key, val := range *in {
					var outVal []string
					if val == nil {
						(*out)[key] = nil
					} else {
						inVal := (*in)[key]
						in, out := &inVal, &outVal
						*out = make(PermissionSet, len(*in))
						copy(*out, *in)
					}
					(*out)[key] = outVal
				}
			}
			(*out)[key] = outVal
		}
	}
}

// DeepCopy is an autogenerated deepcopy function, copying the receiver, creating a new SelinuxProfileSpec.
func (in *SelinuxProfileSpec) DeepCopy() *SelinuxProfileSpec {
	if in == nil {
		return nil
	}
	out := new(SelinuxProfileSpec)
	in.DeepCopyInto(out)
	return out
}

// DeepCopyInto is an autogenerated deepcopy function, copying the receiver, writing into out. in must be non-nil.
func (in *SelinuxProfileStatus) DeepCopyInto(out *SelinuxProfileStatus) {
	*out = *in
	in.StatusBase.DeepCopyInto(&out.StatusBase)
	if in.ActiveWorkloads != nil {
		in, out := &in.ActiveWorkloads, &out.ActiveWorkloads
		*out = make([]string, len(*in))
		copy(*out, *in)
	}
}

// DeepCopy is an autogenerated deepcopy function, copying the receiver, creating a new SelinuxProfileStatus.
func (in *SelinuxProfileStatus) DeepCopy() *SelinuxProfileStatus {
	if in == nil {
		return nil
	}
	out := new(SelinuxProfileStatus)
	in.DeepCopyInto(out)
	return out
}
