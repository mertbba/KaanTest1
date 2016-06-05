#include <stdafx.h>
#include <iostream>
#include <sstream>
#include "binaryTree.h"

using namespace std;

bool back_toMenu=true;
int smallestData;
int largestData;

binaryTree::binaryTree(){
	kok=NULL;
}	

binaryTree::~binaryTree(){
	destroy_tree();
}

void binaryTree::destroy_tree(node *dal)
{
  if(dal!=NULL)
  {
    destroy_tree(dal->left);
    destroy_tree(dal->right);
    delete dal;
  }
}
void binaryTree::destroy_tree(){
	destroy_tree(kok);
	}
}

void binaryTree::add(int data_value, node *dal){
	if (data_value<dal->data){
		if (dal->next!=NULL){
			add(data_value,dal->left);
		}
		else{
			dal->left=new node;
    		dal->left->data=data_value;
    		dal->left->left=NULL; 
    		dal->left->right=NULL;
    	}
	}

	else if(data_value>=dal->data){
		if(dal->right!=NULL){
			add(data_value, dal->right);
		}
		else{
			dal->right=new node;
	    	dal->right->data=data_value;
	    	dal->right->left=NULL;  
	    	dal->right->right=NULL;
	    }
	}
}

void binaryTree::add(int data_value)
{
  if(kok!=NULL){
  	add(data_value,kok);
  }
  else
  {
    kok=new node;
    kok->data=data_value;
    kok->left=NULL;
    kok->right=NULL;
  }
}


node *binaryTree::find(int data_value, node *dal)
{
  if(dal!=NULL)
  {
    if(data_value==dal->data)
      return dal;
    if(data_value<dal->data)
      return find(data_value, dal->left);
    else
      return find(dal_value, dal->right);
  }
  else return NULL;
}

node *binaryTree::find(int data_value)
{
  return find(data_value, kok);
}

void binaryTree::destroy_tree(){
	destroy_tree(root);
}

int binaryTree::max_value(){
	node *head;
	head=kok;
	largestData=kok->data;
	while (kok!=NULL){
		if (kok->data>largestData){
			largestData=kok->data;
		}
		kok=kok->right;
	}

	while (*head!=NULL){
		if (kok->data>largestData){
			largestData=kok->data;
		}
		kok=kok->left;
	}

	return largestData;
}

int binaryTree::min_value(){
	node *head;
	head=kok;
	smallestData=kok->data;

	while (kok!=NULL){
		if (kok->data<smallestData){
			smallestData=kok->data;
		}
		kok=kok->right;
	}

	while (*head!=NULL){
		if (kok->data<smallestData){
			smallestData=kok->data;
		}
		kok=kok->left;
	}

	return smallestData;
}

void binaryTree::viewItems(){
  while (kok!=NULL){
  	kok=kok->left;
  }
  while (kok!=NULL){
  	cout<<kok->data<<endl;
  	kok=kok->right;
  }
}

string menuAnswer(){
	while (back_toMenu){
	cout<<"Binary Search Tree Operations Menu"<<endl;
	cout<<"1-) Add an item."<<endl;
	cout<<"2-) Delete items."<<endl;
	cout<<"3-) View all items."<<endl;
	cout<<"4-) Show max item."<<endl;
	cout<<"5-) Show min item."<<endl;
	cout<<"6-) Find an item."<<endl;
	cout<<"7-) Exit."<<endl;
	cout<<"Your Choice : "<<flush;
	string choice;
	getline(cin,choice);
	return choice;
	}
}

void DoSmth(string input){
	binaryTree::binaryTree();

	if (input=="1"){
		cout<<"What number you wanna add? : ";
		int input_data;
		cin>>input_data;
		while(cin.fail()) {
			cout <<"ERROR, enter a number : " ;
        	cin.clear();
        	cin.ignore();
        	cin >> input_data;
        }

        binaryTree::add(input_data);
    }


	else if (input=="2"){
		binaryTree::~binaryTree();
	}

	else if (input=="3"){

	}

	else if (input=="4"){
		binaryTree::max_value();
	}

	else if (input=="5"){
		binaryTree::min_value();
	}

	else if (input=="6"){
		cout<<"What number you wanna find? : ";
		int input_data;
		cin>>input_data;
		while(cin.fail()) {
			cout <<"ERROR, enter a number : " ;
        	cin.clear();
        	cin.ignore();
        	cin >> input_data;
        }
        binaryTree::find(input_data);
	}

	else if (input=="7"){
		cout<<"Exitting the operations menu..."<<endl;
		back_toMenu=false;
	}

	else{
		cout<<"Whaaaaa?"<<endl;
		string user_choice=menuAnswer();
		DoSmth(user_choice);
	}

}

int main(){
	string user_choice=menuAnswer();
	DoSmth(user_choice);
	return 0;
}