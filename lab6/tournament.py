# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    # argv is a function within the sys class
    # len(sys.argv) shows how many elements are there in the command line
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # here teams is a list of dictionaries
    # each elments in teams is a dictionary type data
    # each team is {'team', 'rating'}
    teams = []
    # TODO: Read teams into memory from file
    with open(sys.argv[1], "r") as file:

        # here DictReader here is different from reader
        # in that this will read the file and put each row as not a list
        # rather as a dictionary that has two things{
        #                                               "team" : team_name ,
        #                                               "rating" : team_score
        #                                           }
        reader = csv.DictReader(file)

        # skip the row of data
        next(reader)

        # row here will read each row of reader
        # that is the row will be the dictinary that contains two elements
        #  {team: , rating: }
        # Notice we need to convert the rating (that is a string type data) into a integer
        # so we can use the score to estimate the posibilities
        for row in reader:
            
            row['rating'] = int(row['rating'])
            
            teams.append(row)

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    with open(sys.argv[1], "r") as file:

        reader = csv.DictReader(file)

        next(reader)
        # copy each row
        for row in reader:

            # we need to creat a new dictionary that store a name and a number
            # so when the name is a input to the dictionary the number is the ouput
            # counts { "team_name" : team_score}
            # when we put 'team' as index to row, we will get a output of the teams name
            # we then store that name in the count clomn
            # for this name we need to set the key (the outout of the counts[name]) to be 0
            # do this for every name in the teams
            count = row['team']
            counts[count] = 0

    # lets do this stimulation N times
    for i in range(N):

        winner = simulate_tournament(teams)

        if winner in counts:
            # check if the name is in the counts dictionary
            # if it is, we make this name as an index and change the key value to plus one
            counts[winner] += 1
            
        else:
            # if it is not, then there is not this team in counts
            counts[winner] = 1
            
    # Print each team's chances of winning, according to simulation
    # team is the team_name, with each iteration for team in counts, we can get into the dictionary
    # the return is the teams name
    # and we sorted the key value. from BIG to SMALL
    # the reverse = True
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    # we took to team and compare their ratings
    # we put "rating" as index to find the key value (which is the scores)
    rating1 = team1["rating"]
    rating2 = team2["rating"]

    # this is the winning prossiblity
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    # this is a randomness within the probability
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    # here the len(teams) - 1 will solve the problem teams[i+1] dont exist
    # notice the range function (, , 2)
    # this will take every two teams every time until the len(teams)
    for i in range(0, len(teams) - 1, 2):
        # for each two team we find a winner
        if simulate_game(teams[i], teams[i + 1]):
            # we use append function to add the name in the winners list
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    winners = []
    # we need to elimanated to only one team
    while len(teams) > 1:
        # we take the remain winners list everytime
        winners = simulate_round(teams)
        # here we updates the team list to only the winners list
        teams = winners
    # return the first team in the team dictionary which is the firs elements in the teams list
    return teams[0]["team"]


if __name__ == "__main__":
    main()
