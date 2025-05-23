﻿# Ansible Inventory Manager

Does not contain source code of the project for privacy.
<br/>

## Table Of Contents

1. [ Description ](#description)
2. [ General Features ](#generalfeatures)
3. [ Usage ](#usage)
4. [ Features To Be Added ](#featurestobeadded)
5. [ Built With](#builtwith)

<a name="description"></a>

## Description

An application that facilitates, accelerates and automates the creation, editing process, and
automation of Ansible Inventories.

<a name="generalfeatures"></a>

## General Features

- Speeding up the process of creating a new inventory by using an Ansible inventory as a
  template.
- Making domain and IP changing processes fast and easy for the user.
- Simplifying the process of creating new Hosts and Groups by providing different
  templates to the user
- Speeding up the editing process by offering variables that have the potential to be added
  to the file as options when editing Host and Group yaml files
- Providing the user with a workspace so that they can continue editing the inventories
  they have previously worked on
- Providing the user with the ability to download the edited inventory to their local

<a name="usage"></a>

## Usage

1. Previously worked inventories can be viewed and selected in the workspace.
   <br/><br/>
   ![alt text](/screenshots/image.png)
   Screenshot 1

2) A new inventory can be uploaded into the workspace. (inventory must be in zip format. There must be an inventory folder inside the zip file.)<br/>
   For example: There must be an inventory-name folder in inventory-name.zip. Inside that folder, there should be hosts file, host_vars and group_vars folders.<br/>
   Example: inventory-name.zip -> inventory-name -> group_vars -> example-group.yml
   <br/><br/>
   ![alt text](/screenshots/image-1.png)
   Screenshot 2<br/><br/>
   ![alt text](/screenshots/image-2.png)
   Screenshot 3

3. Domain and Common IP can be changed in the "Change Environment" section. (Common IP is common first 3 parts of all IPs)<br/><br/>
   ![alt text](/screenshots/image-3.png)

4) The hosts file can be edited.
   <br/><br/>
   ![alt text](/screenshots/image-4.png)
   Screenshot 4
5) Groups in hosts file can also be easily accessed via the search bar.
   <br/><br/>
   ![alt text](/screenshots/image-5.png)
   Screenshot 5

6) A group can be added to the hosts file.
   <br/><br/>
   ![alt text](/screenshots/image-6.png)
7) Using "add an existing group" option, groups that have a yaml file in the group_vars folder but are not in the hosts file can be added to the hosts file.
   <br/><br/>
   ![alt text](/screenshots/image-7.png)
   Screenshot 6

8) To add the group as a subgroup of a group, the parent group(s) can be selected from the "select parent of the group" section. If the group will not be a subgroup of any group, it can be added by clicking "add group without parent".<br/><br/>
   ![alt text](/screenshots/image-8.png)
   Screenshot 7
   <br/><br/>
   ![alt text](/screenshots/image-9.png)
   Screenshot 8
9) Using "create new group" option, a new group can be created.<br/><br/>
   ![alt text](/screenshots/image-10.png)
   Screenshot 9
10) When creating a new group, a group_vars yaml file should be selected as template from the "select template" section. Then, that template is edited and the yaml file of the new group is created. Now a new group yaml file has been created. This new group can be added to the hosts file from the "add an existing group" section.<br/><br/>
    ![alt text](/screenshots/image-11.png)
    Screenshot 10
11) A host can be added to the hosts file.
    <br/><br/>
    ![alt text](/screenshots/image-12.png)
    Screenshot 11
12) Using "add an existing host" option, hosts that have a yaml file in the host_vars folder but are not in the “hosts file” can be added to the hosts file.<br/><br/>
    ![alt text](/screenshots/image-13.png)
    Screenshot 12
13) When adding a host, it is necessary to select which group(s) the host will be a member of. Additionally, a vm tag can be added next to the host added to the hosts file. (e.g. host-name.domain key=value).
    <br/><br/>
    ![alt text](/screenshots/image-14.png)
    Screenshot 13
14) Using "create new host" option, a new host can be created.<br/><br/>
    ![alt text](/screenshots/image-15.png)
    Screenshot 14
15) When creating a new host, a host_vars yaml file should be selected as template from the "select host" section. Then, that template is edited and the yaml file of the new host is created. <br/><br/>
    ![alt text](/screenshots/image-16.png)
    Screenshot 15
16) While editing this template file, it is possible to quickly add items by selecting from the checkboxes on the right. Now a new host yaml file has been created. This new host can be added to the “hosts file” from the "add an existing group" section.<br/><br/>
    ![alt text](/screenshots/image-17.png)
    Screenshot 16
17) Host vars yaml files are edited from the "Host Vars" tab.<br/><br/>
    ![alt text](/screenshots/image-18.png)
    Screenshot 17
    <br/><br/>
    ![alt text](/screenshots/image-19.png)
    Screenshot 18
18) Yaml content can be edited from editor. It is possible to quickly add items by selecting from the checkboxes on the right.<br/><br/>
    ![alt text](/screenshots/image-20.png)
    Screenshot 19
19) Sub-variables of variables can be accessed from the "reach elements" section on the left. so editing subvariables is easier for complex files.
    <br/><br/>
    ![alt text](/screenshots/image-21.png)
    Screenshot 20
20) Everything that can be done in hosts vars can also be done in group vars. Editing can be done from the editor, items can be added quickly with checkboxes, subvariables can be accessed from the left.
    <br/><br/>
    ![alt text](/screenshots/image-22.png)
    Screenshot 21
    <br/><br/>
    ![alt text](/screenshots/image-23.png)
    Screenshot 22
21) This edited inventory should be saved as a template using the "save as template" button. However, this feature is not available in the application. When this button is clicked, this inventory should be saved in a place called “templates”.
22) By clicking the "Download Inventory" button, the edited inventory can be downloaded to local in zip format.
    <br/><br/>
    ![alt text](/screenshots/image-24.png)
    Screenshot 23

<a name="featurestobeadded"></a>

## Features To Be Added

1. Saving the edited inventory as a template (Adding edited inventory to templates by
   clicking the Save as template button)
2. “Create Inventory” tab is currently empty. In the “Create Inventory” tab, creating a new
   inventory by selecting a template and editing it.
   (After the user selects the template in the create inventory tab, the inventory domain and
   common IP will be requested and then the new inventory will be created in the
   workspace and directed to the “update inventory” tab. Update inventory feature is
   already available in the application.)

<a name="builtwith"></a>

## Built With

Node.js<br/>
React
