// SPDX-License-Identifier: MIT
pragma solidity >0.5.0 <= 0.9.0;

contract Lottery1{
    address public manager;
    address payable[] public players; // we have made payable because anyone of the participant can recieve the winning amount

    constructor() {
        manager = msg.sender;
    }

    modifier onlyManager {
        require(manager == msg.sender,"You are not manager");
        _;
    }

    receive() external payable {
        players.push(payable(msg.sender));
        
    }

    function getBalance() view public onlyManager returns(uint){
        return address(this).balance;
    }

    function random()public view returns(uint){
        return uint(keccak256(abi.encodePacked(block.difficulty,block.timestamp,players.length)));
    }

    function selectWinner() public onlyManager returns(address){
        require(players.length >= 3);

        address payable winner;
        uint r = random();
        uint index = r % players.length;

        winner = payable(players[index]);
        winner.transfer(getBalance());
        players = new address payable[](0); // resetting the contract
        return winner;
    }

}