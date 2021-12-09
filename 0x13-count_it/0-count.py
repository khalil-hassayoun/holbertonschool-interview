#!/usr/bin/python3
"""
a recursive function that queries the Reddit API,
parses the title of all hot articles,
and prints a sorted count of given keywords
"""
import requests


def count_words(subreddit, word_list):
    """
    a recursive function that queries the Reddit API,
    parses the title of all hot articles,
    and prints a sorted count of given keywords
    """
    r = requests.get('https://www.reddit.com/r/{}/hot/.json'.format(subreddit),
                     headers={'User-agent': 'Chrome'})
    data = {}
    titles = []
    counts = {}
    for word in word_list:
        if word not in counts:
            counts[word] = 0
    if r.status_code == 200:
        children = r.json().get('data').get('children')
        for item in children:
            titles.append(item.get('data').get('title'))
        for title in titles:
            for k, v in counts.items():
                copy = title[:]
                cut = copy.lower().split(k.lower())
                counts[k] += len(cut) - 1
        duplicates = {}
        for k in counts:
            if counts[k] == 0:
                pass
            elif k.lower() in duplicates:
                duplicates[k.lower()] += counts[k]
            else:
                duplicates[k.lower()] = counts[k]
        sorted_values = sorted(duplicates.values(), reverse=True)
        sorted_dict = {}

        for i in sorted_values:
            for k in duplicates.keys():
                if duplicates[k] == i:
                    sorted_dict[k] = duplicates[k]
        for i in sorted_dict.keys():
            print("{}: {}".format(i, sorted_dict[i]))
