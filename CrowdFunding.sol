// SPDX-License-Identifier: MIT

pragma solidity >0.5.0 <= 0.9.0;

contract CrowdFunding{
    mapping(address => uint) contributors;
    address public manager;
    uint public minimumContribution;
    uint public deadline;
    uint public target;
    uint public raisedAmount;
    uint public noOfContributors;

    struct Request{
        string description;
        address payable recipient;
        uint value;
        bool completed; // to check the transaction is completed or not
        uint noOfVoters; // how many people voted towards it
        mapping(address => bool)voters; // this is like voter list remember festival example for this
    }       
    mapping(uint => Request) requests;
    uint public numRequest;

    constructor(uint _target,uint _deadline)public{
        target = _target;
        manager = msg.sender;
        deadline = block.timestamp + _deadline;
        minimumContribution = 100 wei;
    }

    // users will transfer the ether to contract

    function transferEth() payable public{
        require(block.timestamp <= deadline,"You have already crossed deadline");
        require(msg.value > minimumContribution,"Invalid Funds");

        if(contributors[msg.sender] == 0){
            noOfContributors++; // checking the user is donating for 1st time
        }

        raisedAmount = raisedAmount + msg.value;
        contributors[msg.sender] = contributors[msg.sender] + msg.value;
    }

    function getBalance() public view returns(uint){
        return address(this).balance;
    }

    function refund() public{
        require(block.timestamp > deadline && raisedAmount < target,"You cannot get refund");
        require(contributors[msg.sender] > 0,"You have not contributed");

        address payable user = payable(msg.sender);
        user.transfer(contributors[msg.sender]); // transferring the money

        contributors[msg.sender] = 0; // resetting the amount to 0
    }

    modifier onlyManager(){
        require(msg.sender == manager,"you are not authorised person");
        _;
    }

    // creating the request OR generating the request
    function createRequest(string memory _description,address payable _recipient,uint _value) public onlyManager{
        Request storage newRequest = requests[numRequest];

        numRequest++;

        newRequest.description = _description;
        newRequest.recipient = _recipient;
        newRequest.value = _value;
        newRequest.completed = false;
        newRequest.noOfVoters = 0;
    }  

    function voteRequest(uint _requestNo) public{
        require(contributors[msg.sender] > 0,"You have not contributed the money");
        Request storage currRequest = requests[_requestNo];

        // checking the voter is not voting twice
        currRequest.voters[msg.sender] = true;
        currRequest.noOfVoters++;
    }

    function makePayment(uint _requestNo) public onlyManager{
        Request storage currRequest = requests[_requestNo];

        require(currRequest.completed == false,"Payment has been done already");

        // calculating the majority

        require(currRequest.noOfVoters > (noOfContributors / 2),"No majority");
        currRequest.recipient.transfer(currRequest.value);
        
    }
}