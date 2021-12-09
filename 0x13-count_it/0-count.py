#!/usr/bin/python3
"""Tags counting module"""

import requests


def count_words(subreddit, word_list, word_count={}, after=""):
    """Counts words"""
    if len(word_count) <= 0:
        for word in word_list:
            word_count[word.lower()] = 0

    if after is None:
        sorted_word_count = dict(sorted(
            word_count.items(),
            key=lambda x: (x[1], x[0]),
            reverse=True
            ))
        for k, v in sorted_word_count.items():
            if v > 0:
                print("{}: {}".format(k, v))
        return None

    url = "https://api.reddit.com/r/{}/hot".format(subreddit)
    params = {'limit': 100, 'after': after}
    headers = {'user-agent': 'counting-app'}
    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)

    if response.status_code == 200:
        after = response.json().get("data").get("after")
        children = response.json().get("data").get("children")
        for child in children:
            title_words_lower = child.get("data").get(
                "title").lower().split(" ")
            for word in word_list:
                word_count[word.lower()] += title_words_lower.count(
                    word.lower())
        count_words(subreddit, word_list, word_count, after)
    else:
        return None
