// SPDX-License-Identifier: MIT
pragma solidity >0.5.0 < 0.9.0;

contract Voting{
    address public officer;
    uint public noOfVoters;

    mapping(address=>uint)public candidates;

    struct Voter{
        address userId;
        string name;
        uint age;
        bool isVoted;
    }

    Voter[] public voterList;

    constructor(){
        officer = msg.sender;
    }

    function addToVoterList(string memory _name,uint _age) public{
        Voter memory currVoter = Voter(msg.sender,_name,_age,false);
        voterList.push(currVoter); 
    }

    function createCandidate()public{
        candidates[msg.sender] = 0;
    }

    modifier checkVoter{
        for(uint i = 0;i < voterList.length;i++){
            require((voterList[i].userId == msg.sender) && (voterList[i].isVoted == false),"naale baa");
            voterList[i].isVoted = true;
            break;
        }
        _;
    }

    function castVote(address _vote)public checkVoter{
        
        candidates[_vote] = candidates[_vote] + 1;
    }  

    modifier onlyOfficer(){
        require(msg.sender == officer,"You are not authorised");
        _;
    }
}
