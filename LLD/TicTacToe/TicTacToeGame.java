package TicTacToe;

import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

import TicTacToe.Components.*;

public class TicTacToeGame {
	public Deque<Player> players;
	public Board gameBoard;

	TicTacToeGame(){
		initGame();
	}

	public void initGame(){
		players = new LinkedList<>();
		PlayingPiece crossPiece = new PlayingPieceX();
		Player player1 = new Player("P1", crossPiece);

		PlayingPiece zeroPiece = new PlayingPieceO();
		Player player2 = new Player("P2", zeroPiece);

		players.add(player1);
		players.add(player2);

		gameBoard = new Board(3);
	}

	public String startGame(){
		boolean gotWinner = false;

		while(!gotWinner){
			Player playerTurn = players.removeFirst();

			gameBoard.printBoard();

			List<Pair<Integer, Integer>> freeSpaces = gameBoard.getFreeCells();

			if(freeSpaces.isEmpty()){
				gotWinner = true;
				return "TIE";
			}

			System.out.println("Player: " + playerTurn.name + " Enter row,col : ");
			Scanner sc = new Scanner(System.in);
			String s = sc.nextLine();
			String[] move = s.split(",");
			int rowInput = Integer.valueOf(move[0]);
			int colInput = Integer.valueOf(move[1]);

			boolean pieceAddedSuccessfully = gameBoard.addPiece(rowInput, colInput, playerTurn.playingPiece);
			if(pieceAddedSuccessfully == false){
				System.out.println("Incorrect Postion.");
				players.addFirst(playerTurn);
				continue;
			}
			players.addLast(playerTurn);

			boolean winner = isThereWinner(rowInput, colInput, playerTurn.playingPiece.pieceType);
			if (winner) {
				return playerTurn.name;
			}
		}

		return "";
	}

	public boolean isThereWinner(int row, int column, PieceType pieceType) {

		boolean rowMatch = true;
		boolean columnMatch = true;
		boolean diagonalMatch = true;
		boolean antiDiagonalMatch = true;

		// need to check in row
		for (int i = 0; i < gameBoard.size; i++) {

			if (gameBoard.board[row][i] == null || gameBoard.board[row][i].pieceType != pieceType) {
				rowMatch = false;
			}
		}

		// need to check in column
		for (int i = 0; i < gameBoard.size; i++) {

			if (gameBoard.board[i][column] == null || gameBoard.board[i][column].pieceType != pieceType) {
				columnMatch = false;
			}
		}

		// need to check diagonals
		for (int i = 0, j = 0; i < gameBoard.size; i++, j++) {
			if (gameBoard.board[i][j] == null || gameBoard.board[i][j].pieceType != pieceType) {
				diagonalMatch = false;
			}
		}

		// need to check anti-diagonals
		for (int i = 0, j = gameBoard.size - 1; i < gameBoard.size; i++, j--) {
			if (gameBoard.board[i][j] == null || gameBoard.board[i][j].pieceType != pieceType) {
				antiDiagonalMatch = false;
			}
		}

		return rowMatch || columnMatch || diagonalMatch || antiDiagonalMatch;
	}

}
