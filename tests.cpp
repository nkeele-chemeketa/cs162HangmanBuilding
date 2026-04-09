#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using doctest::Approx;

#include "Hangman.h"

TEST_CASE("test basics")
{
  Hangman game("hello");

  CHECK(game.getWord() == "hello");
  CHECK(game.getBoard() == "_____");
  CHECK(game.getGuessedLetters() == "");
  CHECK(game.getWrongGuesses() == 0);
}

TEST_CASE("test basics2")
{
  Hangman game("banana");

  CHECK(game.getWord() == "banana");
  CHECK(game.getBoard() == "______");
  CHECK(game.getGuessedLetters() == "");
  CHECK(game.getWrongGuesses() == 0);
}

TEST_CASE("makeGuess")
{
  Hangman game("hello");

  CHECK(game.makeGuess('e') == true);
  CHECK(game.getBoard() == "_e___");
  CHECK(game.getGuessedLetters() == "e");
  CHECK(game.getWrongGuesses() == 0);

  CHECK(game.makeGuess('x') == false);
  CHECK(game.getBoard() == "_e___");
  CHECK(game.getGuessedLetters() == "ex");
  CHECK(game.getWrongGuesses() == 1);

  CHECK(game.makeGuess('l') == true);
  CHECK(game.getBoard() == "_ell_");
  CHECK(game.getGuessedLetters() == "exl");
  CHECK(game.getWrongGuesses() == 1);

  CHECK(game.makeGuess('o') == true);
  CHECK(game.getBoard() == "_ello");
  CHECK(game.getGuessedLetters() == "exlo");
  CHECK(game.getWrongGuesses() == 1);

  CHECK(game.makeGuess('h') == true);
  CHECK(game.getBoard() == "hello");
  CHECK(game.getGuessedLetters() == "exloh");
  CHECK(game.getWrongGuesses() == 1);
}

TEST_CASE("isDone")
{
  Hangman game("hello");

  CHECK(game.isDone() == false);

  game.makeGuess('e');
  CHECK(game.isDone() == false);

  game.makeGuess('x');
  CHECK(game.isDone() == false);

  game.makeGuess('l');
  CHECK(game.isDone() == false);

  game.makeGuess('o');
  CHECK(game.isDone() == false);

  game.makeGuess('h');
  CHECK(game.isDone() == true);
}1
