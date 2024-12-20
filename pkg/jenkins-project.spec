Name: jenkins-project
Version: 0.0.0
Release: 1%{?dist}
Summary: Jenkins Project
License: GPL
Source0: %{name}.tar.gz
BuildRequires: boost-devel cmake gcc-c++ make
Requires: boost

%global debug_package %{nil}

%description
Jenkins Project

%prep
%setup -q -n %{name}

%build
cmake CMakeLists.txt
make

%install
mkdir -p $RPM_BUILD_ROOT%{_bindir}
install -m 755 bin/%{name} $RPM_BUILD_ROOT%{_bindir}

%files
%{_bindir}/%{name}

%clean
rm -rf %{buildroot}
